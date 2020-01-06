const   fi='cntdo.inp';
        fo='cntdo.out';
var  test,res,i,n:longint;
    a:array[0..10000]of longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        closE(input);closE(output);
    end;
procedure qs(l,r:longint);
    var i,j,t,m,x:longint;
        begin
            i:=l;
            j:=r;
            m:=random(r-l)+1+l;
            x:=a[m];
            repeat
                while (a[i]<x) do inc(i);
                while (x<a[j]) do dec(j);
                if i<=j then
                    begin
                        t:=a[i];
                        a[i]:=a[j];
                        a[j]:=t;
                        inc(i);
                        dec(j);
                    end;
            until i>j;
            if i<r then qs(i,r);
            if l<j then qs(l,j);
        end;
function chat(l,r,x:longint):longint;
var res,mid:longint;
    begin
        if l>r then exit;
        res:=0;
        repeat
            mid:=(l+r) div 2;
            if x=a[mid] then exit(1);
            if a[mid]<x then l:=mid+1 else r:=mid-1;
        until l>r;
        exit(res);
    end;
begin
    //mo;
    readln(test);
    for test:=1 to test do
        begin
            res:=0;
            readln(n);
            for i:=1 to n do read(a[i]);
            qs(1,n);
            for i:=1 to n do
                if a[i]mod 2=0 then
                    res:=res+chat(1,n,a[i] div 2);
            writeln(res);
        end;
    //dong;
end.
