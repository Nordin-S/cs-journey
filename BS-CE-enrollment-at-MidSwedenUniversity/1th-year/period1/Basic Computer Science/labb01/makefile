%.o : %.cpp
	g++ -c -Wall $<
	
executableName=labb01
objectName = labb01


$(executableName):$(objectName).o
	g++ -o $(executableName) $(objectName).o

clean:
	rm *.o $(executableName) ut.txt

run:$(executableName)
	./$(executableName)

runFileToConsole:$(executableName)
	./$(executableName) < values.txt

runFileToFile:$(executableName)
	./$(executableName) < values.txt > ut.txt