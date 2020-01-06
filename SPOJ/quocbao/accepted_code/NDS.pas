uses math;
const fi='nds.inp';
      fo='nds.out';
        maxn=round(1e7)*2;

    var a,it:array[0..maxn]of longint;
        test,maxx,n,res,ans,l:longint;

    procedure mo;
        begin
            assign(input,fi);reset(input);
            assign(output,fo);rewrite(output);
        end;

    procedure dong;
        begin
            closE(input);closE(output);
        end;

    procedure sinh(l,r,i:longint);
        var mid:longint;
            begin
                if l=r then
                    begin
                        it[i]:=0;
                        exit;
                    end;
                mid:=(l+r) div 2;
                sinh(l,mid,i*2);
                sinh(mid+1,r,i*2+1);
                it[i]:=max(it[i*2],it[i*2+1]);
            end;

    procedure nhap;
        var i:longint;
            begin
                readln(n);
                maxx:=0;
                for i:=1 to n do
                    begin
                        read(a[i]);
                        maxx:=max(maxx,a[i]);
                    end;
                sinh(0,maxx,1);
            end;

    procedure find(u,v,l,r,i:longint);
        var mid:longint;
            begin
                if (r<u) or (v<l) then exit;
                if (u<=l) and (r<=v) then
                    begin
                        res:=max(res,it[i]);
                        exit;
                    end;
                mid:=(l+r) div 2;
                find(u,v,l,mid,i*2);
                find(u,v,mid+1,r,i*2+1);
        end;

    procedure update(u,w,l,r,i:longint);
        var mid:longint;
            begin
                if (r<u) or (u<l) then exit;
                if (l=r) and (l=u) then
                    begin
                    it[i]:=w;
                    exit;
                    end;
                        mid:=(l+r) div 2;
                        update(u,w,l,mid,i*2);
                        update(u,w,mid+1,r,i*2+1);
                        it[i]:=max(it[i*2],it[i*2+1]);
            end;

    procedure xuli;
        var i:longint;
            begin
                ans:=maxlongint;
                readln(l);
                for i:=1 to n do
                    begin
                        res:=0;
                        if a[i]>0 then find(0,a[i]-1,0,maxx,1);
                        if res>=l-1 then ans:=min(ans,a[i]);
                        update(a[i],res+1,0,maxx,1);
                        //writeln(res);
                    end;
                if ans=maxlongint then writeln(-1) else writeln(ans);
            end;

    begin
        //mo;
        readln(test);
        for test:=1 to test do
            begin
                nhap;
                xuli;
            end;
        //dong;
    end.
