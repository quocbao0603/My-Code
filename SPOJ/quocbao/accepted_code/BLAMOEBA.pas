const fi='blamoeba.inp';
      fo='blamoeba.out';
        base=round(1e9)+7;
var x,y,m,n:int64;
    test:longint;

procedure mo;
    begin
        assign(input,fi);reseT(input);
        assign(output,fo);rewrite(output);
    end;
procedure dong;
    begin
        closE(input);closE(output);
    end;
function power(a,n:int64):int64;
    var t:int64;
        begin
            if (n=1) then exit(a) ;
            if (n=0) then exit(1);
            t:=power(a,n div 2);
            t:=(t*t) mod base;
            if n mod 2=1 then
                t:=(t*a) mod base;
            exit(t);
        end;
function ucln(a,b:int64):int64;
    var t:int64;
        begin
            while b>0 do
                begin
                    a:=a mod b;
                    t:=a;
                    a:=b;
                    b:=t;
                end;
            exit(a);
        end;
procedure xuli;
    begin
        readln(m,n);
        y:=power(m,n);
        x:=(power(m,n)-1+base) mod base;
        x:=(x*power(m-1,base-2)) mod base;
        writeln(x,' ',y);
    end;
begin
    //mo;
    readln(tesT);
    while test>0 do
        begin
            dec(test);
            xuli;
        end;
    //dong;
end.
