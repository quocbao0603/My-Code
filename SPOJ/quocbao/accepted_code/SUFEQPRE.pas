const   fi='sufeqpre.inp';
        fo='sufeqpre.out';
var s:ansistring;
    z:array[0..round(1e6)*2]of longint;
    test1,test,n,i,res:longint;
procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewritE(output);
    end;
procedure dong;
    begin
        closE(input);closE(output);
    end;
procedure nhap;
    begin
        readln(s);
    end;
function min(a,b:longint):longint;
    begin
        if a<b then exit(a) else exit(b);
    end;
procedure hamz(s:ansistring);
var l,r:longint;
    begin
        n:=length(s);
        for i:=1 to n do z[i]:=0;
        l:=1;
        r:=1;
        for i:=2 to n do
            begin
                if i<=r then
                    z[i]:=min(z[i-l+1],r-i+1);
                while (i+z[i]<=n) and (s[i+z[i]]=s[z[i]+1]) do inc(z[i]);
                if i+z[i]-1>r then
                    begin
                        r:=i+z[i]-1;
                        l:=i;
                    end;
            end;
    end;
procedure xuat;
    begin
        res:=0;
        for i:=2 to n do
            if i+z[i]-1=n then inc(res);
        writeln('Case ',test1,': ',res);
    end;
begin
    //mo;
    readln(test);
    for test1:=1 to test do
        begin
            nhap;
            hamz(s);
            xuat;
        end;
    //dong;
end.
