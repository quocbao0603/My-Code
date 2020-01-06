    const fi='bdoi16e.inp';
          fo='bdoi16e.out';
            maxn=200000;
            maxx=1000000;
    var free,bait,res,vitri,l,r,x,y,h,a,trace:array[0..maxn]of longint;
        z,d,p,w:array[0..maxn]of int64;
        it:array[0..maxx]of longint;
            i,goc,ll,n,top,count:longint;
    procedure mo;
        begin
            assign(input,fi);reseT(input);
            assign(output,fo);rewrite(output);
        end;
    procedure dong;
        begin
            close(input);closE(output);
        end;
    procedure dfs(u:longint);
        var v:longint;
            begin
                inc(count);
                l[u]:=count;
                vitri[count]:=u;
                for v:=h[u]+1 to h[u+1] do
                    if (trace[a[v]]=0) then
                        begin
                            trace[a[v]]:=u;
                            d[a[v]]:=d[u]+p[v];
                            dfs(a[v]);
                        end;
                r[u]:=count;
            end;
    function search(x:int64):longint;
        var l,r,mid:longint;
            begin
                l:=1;
                r:=top;
                while l<=r do
                    begin
                        mid:=(l+r) div 2;
                        if (w[mid]=x) then exit(mid);
                        if (W[mid]<x) then l:=mid+1 else r:=mid-1;
                    end;
            end;
    procedure qs(l,r:longint);
        var i,j,m:longint;
            x,t:int64;
                begin
                    i:=l;
                    j:=r;
                    m:=random(r-l)+1+l;
                    x:=w[m];
                    repeat
                        while (w[i]<x) do inc(i);
                        while (x<w[j]) do dec(j);
                        if i<=j then
                            begin
                                t:=w[i];
                                w[i]:=w[j];
                                w[j]:=t;
                                inc(i);dec(j);
                            end;
                    until i>j;
                    if i<r then qs(i,r);
                    if l<j then qs(l,j);
                end;
    procedure update(u,w,l,r,i:longint);
        var mid:longint;
            begin
                if (r<u) or (u<l) then exit;
                if (u=l) and (u=r) then
                    begin
                        it[i]:=w;
                        exit;
                    end;
                mid:=(l+r) div 2;
                update(u,w,l,mid,i*2);
                update(u,w,mid+1,r,i*2+1);
                it[i]:=it[i*2]+it[i*2+1];
            end;
    function find(u,v,l,r,i:longint):longint;
        var mid:longint;
            begin
                if (r<u) or (v<l) then exit(0);
                if (u<=l) and (r<=v) then exit(it[i]);
                mid:=(l+r) div 2;
                exit(find(u,v,l,mid,i*2)+find(u,v,mid+1,r,i*2+1));
            end;
    procedure bfs(u:longint);
        var v:longint;
            begin
                inc(count);
                while (ll+1<l[u]) do
                    begin
                        if (trace[ll+1]<n+1) then update(trace[ll+1],1,1,n,1);
                        inc(ll);
                    end;
                res[u]:=find(l[u],r[u],1,n,1);
                for v:=h[u]+1 to h[u+1] do
                        bfs(a[v]);
            end;
    procedure nhap;
    var i:longint;
        begin
            readln(n);
            for i:=1 to n do read(W[i]);
            for i:=1 to n do read(x[i]);
            for i:=1 to n do read(z[i]);
            for i:=1 to n do
                if x[i]=0 then goc:=i else
                    begin
                        y[i]:=i;
                        inc(h[x[i]]);
                    end;
            for i:=1 to n+1 do inc(h[i],h[i-1]);
            for i:=1 to n do
                if x[i]<>0 then
                    begin
                        a[h[x[i]]]:=y[i];
                        p[h[x[i]]]:=z[i];
                        dec(h[x[i]]);
                    end;
            trace[goc]:=-1;
            count:=0;
            dfs(goc);
            for i:=1 to n do d[i]:=d[i]+w[i];
            for i:=1 to n do w[i]:=d[i];
            qs(1,n);
            top:=1;
            for i:=2 to n do
                if w[i]<>w[i-1] then
                    begin
                        inc(top);
                        w[top]:=w[i];
                    end;
            for i:=1 to n do d[i]:=search(d[i]);
            for i:=1 to n do bait[i]:=n+1;
            for i:=n downto 1 do
                begin
                    trace[i]:=bait[d[vitri[i]]];
                    bait[d[vitri[i]]]:=i;
                end;
            for i:=1 to n do
                if free[d[vitri[i]]]=0 then
                    begin
                        update(i,1,1,n,1);
                        free[d[vitri[i]]]:=1;
                    end;
            ll:=0;
            count:=0;
        end;
    begin
       // mo;
        nhap;
        bfs(goc);
        for i:=1 to n do writeln(Res[i]);
       // dong;
    end.
