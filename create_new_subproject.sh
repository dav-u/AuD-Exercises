mkdir $1

sed "s/%name%/$1/" template/CMakeLists.txt > $1/CMakeLists.txt
sed "s/%name%/$1/" template/main.cpp > $1/main.cpp

echo "add_subdirectory (\"$1\")" >> CMakeLists.txt
