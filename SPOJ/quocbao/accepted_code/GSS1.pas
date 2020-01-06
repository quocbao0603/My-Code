uses math;
const fi='gss.inp';
      fo='gss.out';
        oo=-round(1e18);
var a,res,tiento,hauto,tong:array[0..round(1e6)]of int64;
    n:longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        closE(input);closE(output);
    end;
procedure sosanh(i,l,r:longint);
    begin
        tong[i]:=tong[l]+tong[r];
        res[i]:=max(res[l],res[r]);
        res[i]:=max(res[i],hauto[l]+tiento[r]);
        tiento[i]:=max(tiento[l],tong[l]+tiento[r]);
        hauto[i]:=max(hauto[r],tong[r]+hauto[l]);
    end;
procedure sinh(l,r,i:longint);
    var mid:longint;
        begin
            if (l=r) then
                begin
                    res[i]:=a[l];
                    tiento[i]:=a[l];
                    hauto[i]:=a[l];
                    tong[i]:=a[l];
                    exit;
                end;
            mid:=(l+r) div 2;
            sinh(l,mid,i*2);
            sinh(mid+1,r,i*2+1);
            sosanh(i,i*2,i*2+1);
        end;
procedure nhap;
var i:longint;
    begin
        readln(n);
        for i:=1 to n do read(A[i]);
        sinh(1,n,1);
    end;
procedure find(u,v,l,r,i:longint);
    var mid:longint;
        begin
            if (r<u) or (v<l) then exit;
            if (u<=l) and (r<=v) then
                begin
                    sosanh(0,0,i);
                    exit;
                end;
            mid:=(r+l) div 2;
            find(u,v,l,mid,i*2);
            find(u,v,mid+1,r,i*2+1);
        end;
procedure init;
    begin
        res[0]:=oo;
        tiento[0]:=oo;
        hauto[0]:=oo;
        tong[0]:=oo;
    end;
procedure xuat;
var q,l,r:longint;
    begin
        readln(q);
        for q:=1 to q do
            begin
                init;
                readln(l,r);
                find(l,r,1,n,1);
                writeln(res[0]);
            end;
    end;
begin
   // mo;
    nhap;
    xuat;
   // dong;
end.

