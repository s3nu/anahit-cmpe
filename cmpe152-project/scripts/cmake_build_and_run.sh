#!bin/bash
# cd /mnt/d/UbuntuFiles/CMPE152Ubuntu/cmpe152NewLanguage/cmpe152CloudFiles
cd build
cmake ..
make -j
cd ..

./Clouds Assignment7.clouds


# java -jar jasmin-2.4/jasmin.jar assignmentseven.j hello/*.j
java -jar jasmin-2.4/jasmin.jar collisionengine/assignmentseven.j

javac collisionengine/*.java

java -cp .:PascalRTL.jar collisionengine/assignmentseven


# FOR JASMIN TESTING
java -jar jasmin-2.4/jasmin.jar testing.j

javac collisionengine/*.java

java -cp .:PascalRTL.jar collisionengine/testing



# cmake
# PATH="/Applications/CMake.app/Contents/bin":"$PATH"

# ./Clouds Assignment6.clouds
# ./Clouds Assignment7.clouds

# run executable?
# java -jar .:PascalRTL.jar Clouds


# create .jar
cd src/java/hello
jar cv hello.jar *.class
cd ../../..


# use jasmin disassembler
java -jar jasper.jar collisionengine/*.class
