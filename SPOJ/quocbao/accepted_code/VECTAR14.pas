const fi='vectar14.inp';
      fo='vectar14.out';
        du=round(1e9)+7;
var   s:ansistring;
    f:array[-1..1001,-1..1001]of longint;
    test,test1:longint;
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
    begin
        readln(s);
    end;
procedure qhd;
var res,i,k,j,n,t:longint;
    begin
        fillchar(f,sizeof(f),0);
        s:='*'+s; 
        n:=length(s);
        res:=1;
        //f[0,0]:=1;
        f[1,0]:=1;
        for i:=2 to n do
            begin
                if s[i]='(' then t:=1 else t:=-1;
                for j:=i-1 downto 1 do
                    begin
                        for k:=0 to n do
                            begin
                                f[i,k+t]:=(f[j,k]+f[i,k+t]) mod du;
                                //writeln(i,' ',k+t,' ',f[i,k+t],' ',j,' ',k,' ',f[j,k]);
                            end;
                        if s[i]=s[j] then break;
                    end;
                res:=(res+f[i,0])mod du;
            end;
        {for i:=-1 to n do
            begin
            for j:=-1 to n do write(f[i,j],' ');writeln;
            end;   }
        writeln(reS);
    end;
begin
   // mo;
    readln(test);
    for test1:=1 to test do
        begin
            nhap;
            qhd;
        end;
    //dong;
end.
