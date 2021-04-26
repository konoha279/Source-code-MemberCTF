program Xor_easy;
uses crt;
var
    input: integer;
Procedure PrintFlag(key: integer);
var
    arr : array[1..100] of integer;
	c : char;
    i,temp : integer;
begin
        arr[1] := 86;
        arr[2] := 126;
        arr[3] := 118;
        arr[4] := 121;
        arr[5] := 126;
        arr[6] := 105;
        arr[7] := 88;
        arr[8] := 79;
        arr[9] := 93;
        arr[10] := 96;
        arr[11] := 67;
        arr[12] := 43;
        arr[13] := 105;
        arr[14] := 68;
        arr[15] := 40;
        arr[16] := 104;
        arr[17] := 47;
        arr[18] := 98;
        arr[19] := 68;
        arr[20] := 77;
        arr[21] := 113;
        arr[22] := 107;
        arr[23] := 75;
        arr[24] := 105;
        arr[25] := 43;
        arr[26] := 68;
        arr[27] := 43;
        arr[28] := 99;
        arr[29] := 42;
        arr[30] := 41;
        arr[31] := 40;
        arr[32] := 102;
        write('flag: ');
	for i:=1 to 32 do
	begin
            temp := arr[i] xor key;
	       	c := chr(temp);
	       	write(c);
	end;
end;
begin
        clrscr();
        writeln('This is tool make flag. Please enter number to print flag. (Format flag is: MemberCTF{})');
        write('Enter the number: ');
        readln(input);
        PrintFlag(input);
        readln();
end.
