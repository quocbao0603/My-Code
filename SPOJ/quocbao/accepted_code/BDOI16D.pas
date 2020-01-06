uses math;
const fi='bdoi16d.inp';
      fo='bdoi16d.out';
        maxn=round(1e5);
var f:array[0..50,0..maxn]of int64;
    w,a:array[0..maxn]of int64;
    x:array[0..maxn]of longint;
    n,r,k,test,test1:longint;
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
procedure swap64(var i,j:int64);
    var t:int64;
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
            xx:=x[m];
            repeat
                while (X[i]<xx) do inc(i);
                while (xx<x[j]) do dec(j);
                if i<=j then
                    begin
                        swap(x[i],x[j]);
                        swap64(w[i],w[j]);
                        inc(i);dec(j);
                    end;
            until i>j;
            if i<r then qs(i,r);
            if l<j then qs(l,j);
        end;
procedure nhap;
var i:longint;
    begin
        readln(n,r,k);
        for i:=1 to n do read(x[i],w[i]);
        qs(1,n);
    end;
procedure xuli;
    var i,j,l,s:longint;
        ww:int64;
        begin
            for j:=1 to n do
                for i:=1 to k do
                    f[i,j]:=0;
            for j:=1 to k do
                begin
                l:=1;
                ww:=0;
                for i:=1 to n do
                    begin
                        ww:=ww+w[i];
                        s:=x[i]-r*2;
                        while (x[l]<s)and (l<i) do
                            begin
                                ww:=ww-w[l];
                                inc(l);
                            end;
                        f[j,i]:=f[j-1,l-1]+ww;
                        f[j,i]:=max(max(f[j,i],f[j,i-1]),f[j-1,i]);
                    end;
                end;
            writeln(f[k,n]);
            {for i:=1 to k do
                begin
                for j:=1 to n do write(f[i,j],' ');writeln;
                end; }
        end;
begin
   // mo;
    readln(test);
    for test1:=1 to test do
        begin
            write('Case ',test1,': ');
            nhap;
            xuli;
        end;
    //dong;
end.

