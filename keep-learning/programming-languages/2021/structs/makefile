# filnamn: makefile
# Skrivet av: Nordin Suleimani
# Skapat datum: 2021-04-14
# Senast ändrat: 2021-04-27
# Kurs: Objectbaserad Programmering
# Handledare: Jimmy Åhlander

CPPSRCS = main.cpp
INC_CPPSRCS = MinaFuncs.cpp

PROGS = ${CPPSRCS:.cpp=}
PROGS_OBJS = ${CPPSRCS:cpp=o}
INC_OBJS = ${INC_CPPSRCS:cpp=o}
OBJS = ${CPPSRCS:cpp=o} ${INC_CPPSRCS:cpp=o}
HS = ${INC_CPPSRCS:cpp=hpp} 

includesDir = ./includes/

$(PROGS):$(OBJS)
	g++ -o $(PROGS) $(OBJS)

%.o :
	g++ -c -Wall $<

$(PROGS_OBJS) : $(CPPSRCS)

$(INC_OBJS) : $(includesDir)$(INC_CPPSRCS) $(includesDir)$(INC_CPPSRCS)

clean:
	rm *.o $(PROGS)

run:$(PROGS)
	./$(PROGS)