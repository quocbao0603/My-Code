uses math;
const fi='subtleba.inp';
      fo='subtleba.out';
var d,con,xx,yy,zz,a,h,x,y,z,p:array[0..round(1e6)]of longint;
    canh,m,n,q:longint;
    b,res:array[0..20000,0..20]of longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        closE(input);closE(output);
    end;
procedure swap(var i,j:longint);
    var t:longint;
        begin
            t:=i;
            i:=j;
            j:=t;
        end;
procedure qs(l,r:longint);
    var i,j,m,xx:longint;
        begin
            i:=l;
            j:=r;
            m:=random(r-l)+1+l;
            xx:=z[m];
            repeat
                while z[i]>xx do inc(i);
                while xx>z[j] do dec(j);
                if i<=j then
                    begin
                        swap(x[i],x[j]);
                        swap(y[i],y[j]);
                        swap(z[i],z[j]);
                        inc(i);dec(j);
                    end;
            until i>j;
            if i<r then qs(i,r);
            if l<j then qs(l,j);
        end;
procedure themcanh(u,v,w:longint);
    begin
        inc(canh);
        xx[canh]:=u;
        yy[canh]:=v;
        zz[canh]:=w;
    end;
function findset(x:longint):longint;
    begin
        if p[x]=-1 then exit(x) else
            begin
                p[x]:=findset(p[x]);
                exit(p[x]);
            end;
    end;
procedure union(u,v,w:longint);
    begin
        u:=findset(u);
        v:=findset(v);
        if u=v then exit;
        themcanh(u,v,w);
        if con[u]>con[v] then
            begin
                con[u]:=con[u]+con[v];
                p[v]:=u;
            end
        else
            begin
                con[v]:=con[v]+con[u];
                p[u]:=v;
            end;
    end;
procedure ckln;
    var i:longint;
        begin
            readln(n,m,q);
            for i:=1 to n do
                begin
                    con[i]:=1;
                    p[i]:=-1;
                end;
            canh:=0;
            for i:=1 to m do readln(x[i],y[i],z[i]);
            qs(1,m);
            for i:=1 to m do union(x[i],y[i],z[i]);
        end;
procedure xaydothi;
    var i,j:longint;
        begin
            for i:=1 to n+1 do h[i]:=0;
            m:=n-1;
            for i:=1 to m do
                begin
                    x[i]:=xx[i];
                    y[i]:=yy[i];
                    z[i]:=zz[i];
                    inc(h[x[i]]);
                    inc(h[y[i]]);
                    //writeln(x[i],' ',y[i],' ',z[i]);
                end;
            for i:=1 to n+1 do inc(h[i],h[i-1]);
            for i:=1 to m do
                begin
                    a[h[x[i]]]:=y[i];
                    p[h[x[i]]]:=z[i];
                    dec(h[x[i]]);

                    a[h[y[i]]]:=x[i];
                    p[h[y[i]]]:=z[i];
                    dec(h[y[i]]);
                end;
            for i:=1 to n do
                for j:=0 to 20 do
                    begin
                        res[i,j]:=maxlongint;
                        b[i,j]:=0;
                    end;
            d[1]:=1;
            for i:=2 to n do d[i]:=0;
        end;
procedure dfs(u:longint);
    var v:longint;
        begin
            //writeln(u);
            for v:=h[u]+1 to h[u+1] do
                if d[a[v]]=0 then
                    begin
                        d[a[v]]:=d[u]+1;
                        b[a[v],0]:=u;
                        res[a[v],0]:=p[v];
                        dfs(a[v]);
                    end;
        end;
procedure rmq;
    var i,j:longint;
        begin
            b[1,0]:=1;
            for j:=1 to 20 do
                for i:=1 to n do
                    begin
                        b[i,j]:=b[b[i,j-1],j-1];
                        res[i,j]:=min(res[i,j-1],res[b[i,j-1],j-1]);
                    end;
            {for i:=1 to n do
                begin
                for j:=0 to 20 do write(res[i,j],' ');writeln;
                end;  }
        end;
function lca(u,v:longint):longint;
    var k,ans,i:longint;
        begin
            ans:=maxlongint;
            if d[u]>=d[v] then
                begin
                    k:=d[u]-d[v];
                    for i:=20 downto 0 do
                        if k>=1 shl i then
                            begin
                                k:=k-1 shl i;
                                ans:=min(ans,res[u,i]);
                                u:=b[u,i];
                            end;
                    if u=v then exit(ans);
                    for i:=20 downto 0 do
                        if b[u,i]=b[v,i] then
                        else
                            begin
                                ans:=min(ans,res[u,i]);
                                ans:=min(ans,res[v,i]);
                                u:=b[u,i];
                                v:=b[v,i];
                            end;
                    ans:=min(ans,res[u,0]);
                    ans:=min(ans,res[v,0]);
                    exit(ans);
                end
            else exit(lca(v,u));
        end;
procedure xuli;
    var i,u,v:longint;
        begin
            for i:=1 to q do
                begin
                    readln(u,v);
                    writeln(lca(u,v));
                end;
        end;
begin
    //mo;
    while seekeof=false do
        begin
            ckln;
            xaydothi;
            dfs(1);
            rmq;
            xuli;
        end;
    //dong;
end.

