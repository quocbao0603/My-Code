const fi='vectar12.inp';
      fo='vectar12.out';
        du=1000000007;

var  f:array[-1..7001,-1..7001]of longint;
    i,j,k,n,test:longint;

procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
    end;

procedure dong;
    begin
        closE(input);closE(output);
    end;

procedure qhd;
    begin
        f[0,0]:=1;
        f[1,1]:=1;
        f[1,0]:=1;
        for i:=2 to 7000 do
            for j:=0 to 7000 do
                begin
                f[i,j]:=(f[i-1,j-1]+f[i-1,j])mod du;
                f[i,j]:=(f[i,j]+f[i-1,j+1]) mod du;
                end;
    end;

procedure nhap;
    begin
        readln(n,k);
        writeln(f[n,k]);
    end;

begin
   // mo;
    qhd;
    readln(test);
    for test:=1 to test do
        nhap;
    //dong;
end.
