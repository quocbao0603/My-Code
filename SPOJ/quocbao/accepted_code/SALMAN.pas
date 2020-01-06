uses math;
const fi='salman.inp';
      fo='salman.out';
        maxn=round(1e5)*6;
var
    test,test1,count,i,n,m,q,u,v:longint;
    res,resw:int64;

        lazy,d,itmin,ittong:array[0..maxn]of int64;
        sohieuid,x,y,a,h,id,trace,tail:array[0..maxn]of longint;

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
        count:=0;
        fillchar(lazy,sizeof(lazy),0);
        fillchar(id,sizeof(id),0);
        fillchar(trace,sizeof(trace),0);
        fillchar(h,sizeof(h),0);
        fillchar(ittong,sizeof(ittong),0);
        fillchar(itmin,sizeof(itmin),0);
    end;
procedure nhap;
    var i:longint;
        w:int64;
        begin
            //readln;
            m:=0;
            readln(n,q);
            init;
            for v:=1 to n do
                begin
                    readln(u,w);
                    d[v]:=w;
                    if u=0 then continue;
                    inc(m);
                    x[m]:=u;
                    y[m]:=v;
                end;
            for i:=1 to m do
                begin
                    inc(H[x[i]]);
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
            inc(count);
            id[u]:=count;
            sohieuid[count]:=u;
            for v:=h[u]+1 to h[u+1] do
                if trace[a[v]]=0 then
                    begin
                        trace[a[v]]:=u;
                        dfs(a[v]);
                    end;
            tail[u]:=count;
        end;
procedure sinh(l,r,i:longint);
    var mid:longint;
        begin
            if l=r then
                begin
                    itmin[i]:=d[sohieuid[l]];
                    ittong[i]:=d[sohieuid[l]];
                    exit;
                end;
            mid:=(l+r) div 2;
            sinh(l,mid,i*2);
            sinh(mid+1,r,i*2+1);
            itmin[i]:=min(itmin[i*2],itmin[i*2+1]);
            ittong[i]:=ittong[i*2]+ittong[i*2+1];
            //writeln(l,' ',r,' ',itmin[i],' ',ittong[i]);
        end;
procedure update(u,v:longint;w:int64;l,r,i:longint);
    var mid:longint;
        begin
            //update xuong con
            ittong[i]:=ittong[i]+(lazy[i])*int64(r-l+1);
            itmin[i]:=itmin[i]+lazy[i];
            lazy[i*2]:=lazy[i*2]+lazy[i];
            lazy[i*2+1]:=lazy[i*2+1]+lazy[i];
            lazy[i]:=0;
            if (r<u) or (v<l) then exit;
            if (u<=l) and (r<=v) then
                begin
                    lazy[i*2]:=lazy[i*2]+w;
                    lazy[i*2+1]:=lazy[i*2+1]+w;
                    ittong[i]:=ittong[i]+w*int64(r-l+1);
                    itmin[i]:=itmin[i]+w;
                    exit;
                end;

            mid:=(l+r) div 2;
            update(u,v,w,l,mid,i*2);
            update(u,v,w,mid+1,r,i*2+1);

            ittong[i]:=ittong[i*2]+ittong[i*2+1];
            itmin[i]:=min(itmin[i*2],itmin[i*2+1]);
        end;
procedure find(u,v,l,r,i:longint);
    var mid:longint;
        begin
            ittong[i]:=ittong[i]+(lazy[i])*int64(r-l+1);
            itmin[i]:=itmin[i]+lazy[i];
            lazy[i*2]:=lazy[i*2]+lazy[i];
            lazy[i*2+1]:=lazy[i*2+1]+lazy[i];
            lazy[i]:=0;

            if (r<u) or (v<l) then exit;
            if (u<=l) and (r<=v) then
                begin
                    res:=res+ittong[i];
                    resw:=min(resw,itmin[i]);
                    //writeln(l,' ',r,' ',res,' ',resw);
                    exit;
                end;
            mid:=(l+r) div 2;
            find(u,v,l,mid,i*2);
            find(u,v,mid+1,r,i*2+1);
            ittong[i]:=ittong[i*2]+ittong[i*2+1];
            itmin[i]:=min(itmin[i*2],itmin[i*2+1]);
        end;
procedure xuli;
var i,loai,sohieu:longint;
    begin
        sinh(1,n,1);
        for i:=1 to q do
            begin
                readln(loai,sohieu);
                res:=0;
                resw:=1000;
                if loai=1 then
                    begin
                        find(id[sohieu],tail[sohieu],1,n,1);
                        writeln(Res);
                    end
                else
                    begin
                        find(id[sohieu],tail[sohieu],1,n,1);
                        update(id[sohieu],tail[sohieu],resw,1,n,1);
                    end;
                //writeln;writeln;
            end;
    end;
begin
    //mo;
    readln(test);
    for test1:=1 to test do
        begin
            writeln('Case ',test1,':');
            nhap;
            trace[1]:=-1;
            dfs(1);
            xuli;
            //for i:=1 to n do writeln(d[i]);
            //for i:=1 to n do writeln(id[i],' ',tail[i]);
        end;
    //dong;
end.
