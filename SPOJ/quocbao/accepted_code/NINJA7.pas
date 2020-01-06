const fi='ninja7.inp';
fo='ninja7.out';
maxn=round(1e6);
var  kq,s:int64;
i,n,test:longint;
a,b:array[0..maxn]of int64;
procedure qs(l,r:longint);
var i,j,m,x:longint;
t:int64;
  begin
    i:=l;
    j:=r;
    m:=(i+j) div 2;
    x:=a[m];
    repeat
      while a[i]>x do inc(i);
      while a[j]<x do dec(j);
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
begin
 // assign(input,fi);reseT(input);
 // assign(output,fo);rewrite(output);
    readln(test);
    for test:=1 to test do
      begin
        s:=0;
        kq:=0;
        readln(n);
        for i:=1 to n do reaD(a[i]);
        for i:=1 to n do read(b[i]);
        for i:=1 to n do
            a[i]:=a[i]-b[i];
        qs(1,n);
        for i:=1 to n do
          begin
          s:=s+a[i];
          if s<0 then break;
          inc(kq);
          end;
        writeln(kq);
      end;
  //closE(input);closE(output);
end.
