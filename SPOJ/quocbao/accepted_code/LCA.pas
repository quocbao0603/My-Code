uses math;
const   fi='lca.inp';
        fo='lca.out';
        maxn=round(1e4)*2;
var test,test1,n,m,i,p,j,q,u,v:longint;
    x,y,h,a,cha,bac:array[0..maxn]of longint;
    rmq:array[0..maxn,0..100]of longint;
    goc,free:array[0..maxn]of boolean;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        close(input);closE(output);
    end;
procedure nhap;
    begin
        readln(n);
        m:=0;
        for i:=1 to n do
            begin
                read(p);
                for j:=1 to p do
                    begin
                        inc(m);
                        x[m]:=i;
                        read(y[m]);
                        inc(h[x[m]]);
                        goc[y[m]]:=false;
                    end;
            end;
        for i:=1 to n+1 do inc(h[i],h[i-1]);
        for i:=1 to m do
            begin
                a[h[x[i]]]:=y[i];
                dec(h[x[i]]);
            end;
    end;
procedure dfs(u:longint);
var v:longint;
    begin
        for v:=h[u]+1 to h[u+1] do
            if (free[a[v]]=true) then
                begin
                    bac[a[v]]:=bac[u]+1;
                    cha[a[v]]:=u;
                    free[a[v]]:=false;
                    dfs(a[v]);
                end;
    end;
procedure xuli;
    begin
        for i:=1 to n do
            if goc[i]=true then break;
        free[i]:=false;
        dfs(i);
        for i:=1 to n do rmq[i,0]:=cha[i];
        for j:=1 to trunc(log2(n)) do
            begin
                for i:=1 to n do
                    rmq[i,j]:=rmq[rmq[i,j-1],j-1];
            end;
    end;
procedure init;
    begin
        fillchar(goc,sizeof(goc),true);
        fillchar(free,sizeof(free),true);
        fillchar(cha,sizeof(cha),0);
        fillchar(bac,sizeof(bac),0);
        fillchar(rmq,sizeof(rmq),0);
        fillchar(h,sizeof(h),0);
    end;
function lca(u,v:longint):longint;
var res,k:longint;
    begin
        if bac[u]>=bac[v] then
            begin
                k:=bac[u]-bac[v];
                if k>0 then
                    for i:=trunc(log2(k)) downto 0 do
                        if k>=1 shl i then
                            begin
                                u:=rmq[u,i];
                                k:=k-1 shl i;
                            end;
                if u=v then exit(u);
                for i:=trunc(log2(n)) downto 0 do
                    if rmq[u,i]<>rmq[v,i] then
                        begin
                            u:=rmq[u,i];
                            v:=rmq[v,i];
                        end
                    else res:=rmq[u,i];
                exit(res);
            end
        else exit(lca(v,u));
    end;
procedure xuat;
    begin
        writeln('Case ',test1,':');
        readln(q);
        for q:=1 to q do
            begin
                readln(u,v);
                writeln(lca(u,v));
            end;
    end;
begin
    //mo;
    readln(test);
    for test1:=1 to test do
        begin
            init;
            nhap;
            xuli;//danh bac + rmq
            xuat;
            {for i:=1 to n do
                begin
                for j:=0 to n do write(rmq[i,j],' ');writeln;
                end;                }
        end;
    //dong;
end.
