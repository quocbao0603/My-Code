uses math;
const   fi='qtree2.inp';
        fo='qtree2.out';
var i,j,n,top,test1,test,res:longint;
    pos,h,x,y,a,heap,cha,bac:array[0..round(1e5)]of longint;
    z,p,d:array[0..round(1e5)]of int64;
    free:array[0..round(1e5)]of boolean;
    rmq:array[0..round(1e4),0..20]of longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        closE(input);closE(output);
    end;
procedure init;
    begin
        fillchar(h,sizeof(h),0);
        fillchar(pos,sizeof(pos),0);
        top:=0;
        fillchar(free,sizeof(free),true);
        fillchar(cha,sizeof(cha),0);
        fillchar(rmq,sizeof(rmq),0);
        fillchar(bac,sizeof(bac),0);
    end;
procedure nhap;
var i:longint;
    begin
        init;
        readln(n);
        for i:=1 to n-1 do
            begin
                readln(x[i],y[i],z[i]);
                inc(h[x[i]]);
                inc(h[y[i]]);
            end;
        for i:=1 to n+1 do inc(h[i],h[i-1]);
        for i:=1 to n-1 do
            begin
                a[h[x[i]]]:=y[i];
                p[h[x[i]]]:=z[i];
                dec(h[x[i]]);
                a[h[y[i]]]:=x[i];
                p[h[y[i]]]:=z[i];
                dec(h[y[i]]);
            end;
    end;
procedure swap(i,j:longint);
    var t:longint;
        begin
            t:=heap[i];
            heap[i]:=heap[j];
            heap[j]:=t;
            pos[heap[i]]:=i;
            pos[heap[j]]:=j;
        end;
procedure up(i:longint);
    var j:longint;
        begin
            j:=i div 2;
            if (i=1) or (d[heap[i]]>=d[heap[j]]) then exit;
            swap(i,j);
            up(j);
        end;
procedure down(i:longint);
    var j:longint;
        begin
            j:=i*2;
            if (j>top) then exit;
            if (j<top) and (d[heap[j]]>=d[heap[j+1]]) then inc(j);
            if (d[heap[i]]>=d[heap[j]]) then swap(i,j);
            down(j);
        end;
function pop:longint;
var t:longint;
    begin
        t:=heap[1];
        swap(1,top);
        pos[heap[top]]:=0;
        dec(top);
        down(1);
        exit(t);
    end;
procedure push(x:longint);
    begin
        inc(top);
        heap[top]:=x;
        pos[x]:=top;
        up(top);
    end;
procedure dij;
var i,u,v:longint;
    begin
        for i:=1 to n do d[i]:=round(1e18);
        d[1]:=0;
        push(1);
        for i:=1 to n do
            begin
                u:=pop;
                free[u]:=false;
                for v:=h[u]+1 to h[u+1 ] do
                    if (free[a[v]]=true) and (d[a[v]]>d[u]+p[v]) then
                        begin
                            d[a[v]]:=d[u]+p[v];
                            if (pos[a[v]]=0) then push(a[v]) else up(pos[a[v]]);
                        end;
            end;
    end;
procedure lca(u,v:longint);
var k,i,j:longint;
    begin
        if bac[u]>=bac[v] then
            begin
                k:=bac[u]-bac[v];
                if k>0 then
                    begin
                        for i:=trunc(log2(n)) downto 0 do
                            if k>=1 shl i then
                                begin
                                    u:=rmq[u,i];
                                    k:=k-1 shl i;
                                end;
                    end;
                if u=v then
                    begin
                        res:=u;
                        exit;
                    end;
                for i:=trunc(log2(n)) downto 0 do
                    if rmq[u,i]=rmq[v,i] then res:=rmq[u,i]
                    else
                        begin
                            u:=rmq[u,i];
                            v:=rmq[v,i];
                        end;
            end
        else lca(v,u);
    end;
procedure timkhoangcach;
var x,y:char;
a,b:longint;
    begin
        read(x,y);
        readln(a,b);
        lca(a,b);
        writeln(d[a]+d[b]-2*d[res]);
    end;
procedure timchathu(k,u:longint);
var i:longint;
    begin
        for i:=trunc(log2(n)) downto 0 do
            if k>=1 shl i then
                begin
                    u:=rmq[u,i];
                    k:=k-1 shl i;
                end;
        writeln(u);
    end;
procedure timdinhthuk;
var h:char;
a,b,k,i,kca,kcb:longint;
    begin
        read(h);
        readln(a,b,k);
        lca(a,b);
        kca:=bac[a]-bac[res]+1;
        kcb:=bac[b]-bac[res]+1;
        if k<=kca then timchathu(k-1,a) else timchathu(kca+kcb-1-k,b);
    end;
procedure xuli;
var x,y:char;
    begin
        while seekeof=false do
            begin
                read(x,y);
                if x='K' then timdinhthuk else
                    if y='O' then
                        begin
                        readln;
                        exit;
                        end
                    else timkhoangcach;
            end;
    end;
procedure dfs(u:longint);
var v:longint;
    begin
        for v:=h[u]+1 to h[u+1] do
            if cha[a[v]]=0 then
                begin
                    cha[a[v]]:=u;
                    bac[a[v]]:=max(bac[a[v]],bac[u]+1);
                    dfs(a[v]);
                end;
    end;
procedure rmqlca;
var i,j:longint;
    begin
        cha[1]:=-1;
        dfs(1);
        for i:=2 to n do
            rmq[i,0]:=cha[i];
        for j:=1 to trunc(log2(n)) do
            for i:=1 to n do
                rmq[i,j]:=rmq[rmq[i,j-1],j-1];
    end;
begin
    //mo;
    readln(test);
    for test1:=test downto 1 do
        begin
            nhap;
            dij;
            rmqlca;
            xuli;
            if test1 <> 1 then writeln;
        end;
    //dong;
end.
