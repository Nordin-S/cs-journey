%.o : %.cpp
	g++ -c -Wall $<
	
executableName=labb04
objectName = labb04


$(executableName):$(objectName).o
	g++ -o $(executableName) $(objectName).o

clean:
	rm *.o $(executableName)

run:$(executableName)
	./$(executableName)
