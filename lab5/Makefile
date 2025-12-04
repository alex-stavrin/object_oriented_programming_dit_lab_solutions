MY=my_solution
IN=instructor_solution

m:
	mkdir -p build
	mkdir -p build/${MY}
	g++ -c ${MY}.cpp -o build/${MY}/${MY}.o
	g++ build/${MY}/${MY}.o -o build/${MY}/${MY}.out
	./build/${MY}/${MY}.out

i:
	mkdir -p build
	mkdir -p build/${IN}
	g++ -c ${IN}.cpp -o build/${IN}/${IN}.o
	g++ build/${IN}/${IN}.o -o build/${IN}/${IN}.out
	./build/${IN}/${IN}.out