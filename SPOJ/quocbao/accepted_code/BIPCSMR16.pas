uses math;
const fi='bipcsmr16.inp';
      fo='bipcsmr16.out';
var res:int64;
    a:array[1..3]of int64;
    i,j,test,test1:longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        closE(input);closE(output);
    end;
procedure nhap;
var t,x,y,ans:int64;
    begin
        readln(a[1],a[2],a[3]);
        for i:=1 to 3 do
                    for j:= i+1 to 3 do
                        if a[i]>a[j] then
                            begin
                                t:=a[i];
                                a[i]:=a[j];
                                a[j]:=t;
                            end;
        x:=a[1]+a[2];
        res:=a[1]+a[2]+a[3];
        ans:=max(0,a[3]-(a[1]+a[2])*2);
        res:=res-ans;
        writeln(res div 3);
    end;
begin
   // mo;
    readln(TesT);
    for test:=1 to test do
            nhap;
   // dong;
end.
