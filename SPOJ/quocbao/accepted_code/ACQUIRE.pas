{$mode objfpc}
//uses math;
const fi='acquire.inp';
      fo='acquire.out';
var cd,cr:array[0..round(1e5)]of longint;
    f,a,b:array[0..round(1e5)]of int64;
    n,top,cuctrai:longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        closE(input);close(output);
    end;
procedure swap(var i,j:longint);
    var t:longint;
        begin
            t:=i;
            i:=j;
            j:=t;
        end;
procedure qs(l,r:longint);
    var i,j,m,x,y:longint;
        begin
            i:=l;
            j:=r;
            m:=random(r-l)+1+l;
            x:=cd[m];
            y:=cr[m];
            repeat
                while (cd[i]<x) or (cd[i]=x) and (cr[i]<y) do inc(i);
                while (x<cd[j]) or (x=cd[j]) and (y<cr[j]) do dec(j);
                if i<=j then
                    begin
                        swap(cd[i],cd[j]);
                        swap(cr[i],cr[j]);
                        inc(i);
                        dec(j);
                    end;
            until i>j;
            if i<r then qs(i,r);
            if l<j then qs(l,j);
        end;
procedure nhap;
    var i,top:longint;
        begin
            readln(n);
            for i:=1 to n do readln(cd[i],cr[i]);
            qs(1,n);
            top:=1;
            for i:=2 to n do
                begin
                    while (top>0)and (cr[i]>=cr[top]) do dec(top);
                     inc(top);
                    cd[top]:=cd[i];
                    cr[top]:=cr[i];
                end;
            n:=top;
            //writeln(top);
            //for i:=1 to top do writeln(cd[i],' ',cr[i]);
        end;
function min(a,b:int64):int64;
    begin
        if a<b then exit(a) else exit(b);
    end;
procedure trau;
    var i,j:longint;
        oo:int64;
        begin
            oo:=round(1e18);
            for i:=1 to n do
                begin
                f[i]:=oo;
                for j:=0 to i-1 do
                    f[i]:=min(f[i],cd[i]*cr[j+1]+f[j]);
                end;
            writeln(f[n]);
        end;
function cuctieu(i,x:longint):int64;
    var t:int64;
        begin
            t:=int64(x)*int64(a[i])+int64(b[i]);
            exit(t);
        end;
function giao(i,j:longint):extended;
    var  x:extended;
        begin
            x:=(b[j]-b[i])/(a[j]-a[i]);
            exit(x);
        end;
procedure them(xx,yy:int64);
    begin
        inc(top);
        a[top]:=xx;
        b[top]:=yy;
        while (top>2) and (giao(top,top-1)>=giao(top,top-2)) do
            begin
                dec(top);
                a[top]:=a[top+1];
                b[top]:=b[top+1];
    end;    end;
procedure full;
    var i:longint;
        begin
            cuctrai:=1;
            them(cr[1],0);
            for i:=1 to n do
                begin
                    while (cuctrai<top) and (cuctieu(cuctrai,cd[i])>=cuctieu(cuctrai+1,cd[i])) do inc(cuctrai);
                    f[i]:=cuctieu(cuctrai,cd[i]);
                    if i<n then
                        begin
                            them(cr[i+1],f[i]);
                        end;
                    //writeln(cuctrai,' ',top);
                end;
            //for i:=1 to n do writeln(f[i]);
            writeln(f[n]);
        end;
begin
    //mo;
    nhap;
    //trau;
    full;
    //dong;
end.

