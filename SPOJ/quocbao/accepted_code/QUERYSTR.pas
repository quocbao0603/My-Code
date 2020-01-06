const fi='querystr.inp';
      fo='querystr.out';

var z:array[0..round(1e6)*5]of longint;
    t,s:ansistring;
    n,i,q,test:longint;

procedure mo;
    begin
        assign(input,fi);reset(input);
        assign(output,fo);rewritE(output);
    end;
procedure dong;
    begin
        closE(input);closE(output);
    end;
function min(a,b:longint):longint;
    begin
        if a<b then exit(a) else exit(b);
    end;
procedure hamz(s:ansistring);
    var l,r:longint;
        begin
            for i:=1 to n do z[i]:=0;
            l:=1;
            r:=1;
            for i:=2 to n do
                begin
                    if i<=r then
                        z[i]:=min(z[i-l+1],r-i+1);
                    while (z[i]+i<=n) and (s[z[i]+i]=s[z[i]+1]) do inc(z[i]);

                    if i+z[i]-1>r then
                                begin
                                    l:=i;
                                    r:=i+z[i]-1;
                                end;
                end;
            z[1]:=n;
        end;
procedure nhap;
    begin
        readln(t);
        n:=length(t);
        s:='';
        for i:=1 to n do s:=t[i]+s;
        hamz(s);
    end;
procedure xuat;
    begin
        readln(q);
        while q>0 do
            begin
                dec(q);
                readln(i);
                writeln(z[n+1-i]);
            end;
    end;
begin
    //mo;
    readln(test);
    while test>0 do
        begin
            dec(test);
            nhap;
            xuat;
        end;
    //dong;
end.
