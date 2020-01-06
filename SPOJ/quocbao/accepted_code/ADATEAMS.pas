const fi='adateams.inp';
      fo='adateams.out';
        base=round(1e9)+7;
var  f:array[0..round(1e6)]of int64;
    n,a,b,d:longint;
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
        readln(n,a,b,d);
    end;
procedure tienxuli;
    var i:longint;
        begin
            f[0]:=1; 
            for i:=1 to 1000000 do f[i]:=(f[i-1]*int64(i)) mod base;
        end;
function lt(a,b:int64):int64;
    var t:int64;
        begin
            if b=0 then exit(1);
            if b=1 then exit(a);
            t:=lt(a,b div 2);
            t:=(t*t) mod base;
            if b mod 2=1 then t:=(t*a)mod base;
            exit(t);
        end;
procedure xuli;
var res,ans:int64;
    begin
        res:=f[n];
        res:=(res*lt(f[a],base-2))mod base;
        res:=(res*lt(f[n-a],base-2))mod base;
        ans:=f[b];
        ans:=(ans*lt(f[d],base-2)) mod base;
        ans:=(ans*lt(f[b-d],base-2))mod base;
        ans:=lt(ans,a);
        res:=(res*ans) mod base;
        writeln(res);
    end;
begin
    //mo;
    tienxuli;
    while seekeof=false do
        begin
            nhap;
            xuli;
        end;
    //dong;
end.
