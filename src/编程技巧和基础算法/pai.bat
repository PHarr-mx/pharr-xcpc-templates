:again
data.exe > data.in
std.exe < data.in > std.out
test.exe < data.in > test.out
fc std.out test.out
if not errorlevel 1 goto again