executableName = labb03

hppDir = ./includes/headerfiles/
cppDir = ./includes/

objectName = labb03.o ReadFileToVector.o IsSorted.o MergeFile.o


$(executableName):$(objectName)
	g++ -o $(executableName) $(objectName)

%.o :
	g++ -c -Wall $<

labb03.o : labb03.cpp
ReadFileToVector.o : $(cppDir)ReadFileToVector.cpp $(hppDir)ReadFileToVector.hpp
IsSorted.o : $(cppDir)IsSorted.cpp $(hppDir)IsSorted.hpp
MergeFile.o : $(cppDir)MergeFile.cpp $(hppDir)MergeFile.hpp

clean:
	rm *.o $(executableName) C

run:$(executableName)
	./$(executableName)