const fi='policemen.inp';
      fo='policemen.out';
var a,h,x,y,d:array[0..round(1e5)]of longint;
b:array[0..round(1e5),0..20]of longint;
    n:longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        closE(input);close(output);
    end;
procedure nhap;
    var i:longint;
        begin
            readln(n);
            for i:=1 to n-1 do
                begin
                    readln(x[i],y[i]);
                    inc(H[x[i]]);
                    inc(H[y[i]]);
                end;
            for i:=1 to n+1 do inc(h[i],h[i-1]);
            for i:=1 to n-1 do
                begin
                    a[h[x[i]]]:=y[i]; dec(h[x[i]]);
                    a[h[y[i]]]:=x[i]; dec(h[y[i]]);
                end;
            for i:=1to n do d[i]:=-1;
            d[1]:=0;
            b[1,0]:=1;
        end;
procedure dfs(u:longint);
    var v:longint;
        begin
            for V:=h[u]+1 to h[u+1] do
                if d[a[v]]=-1 then
                    begin
                        b[a[v],0]:=u;
                        d[a[v]]:=d[u]+1;
                        dfs(a[v]);
                    end;
        end;
function lca(u,v:longint):longint;
    var k,i,res:longint;
        begin
            if d[u]>=d[v] then
                begin
                    k:=d[u]-d[v];
                    for i:=20 downto 0 do
                        if k>=1 shl i then
                            begin
                                u:=b[u,i];
                                k:=k-1 shl i;
                            end;
                    if u=v then exit(u);
                    for i:=20 downto 0 do
                        if b[u,i]=b[v,i] then res:=b[u,i] else
                            begin
                                u:=b[u,i];
                                v:=b[v,i];
                            end;
                    exit(res);
                end
            else exit(lca(v,u));
        end;
procedure truyvan;
    var a,b,i,m:longint;
        begin
            readln(m);
            for i:=1 to m do
                begin
                    readln(a,b);
                    if d[a]<d[b] then writeln('NO')else
                        begin
                            writeln('YES ',lca(a,b));
                        end;
                end;
        end;
procedure rmq;
var i,j:longint;
    begin
        for j:=1 to 20 do
            for i:=1 to n do
                b[i,j]:=b[b[i,j-1],j-1];
    end;
begin
    //mo;
    nhap;
    dfs(1);
    rmq;
    truyvan;
    //dong;
end.
