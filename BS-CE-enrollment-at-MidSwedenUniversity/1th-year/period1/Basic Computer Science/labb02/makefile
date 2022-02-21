executableName=labb02
objectName = labb02


$(executableName):$(objectName).o
	g++ -o $(executableName) $(objectName).o

%.o : %.cpp
	g++ -c -Wall $<

clean:
	rm *.o $(executableName)
run:$(executableName)
	./$(executableName)
