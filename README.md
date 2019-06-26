#Visualization
We use for visualization networkx library
#Input Of Python Program: 
	1. Exe file of c++ program that contains 3 algorithm
	2. Text file that contain the input that will be taken by c++ program
	3. python 

#Output Of Python Program:
	1. PNG representing Degree Centrality
	2. PNG representing Closeness Centrality
	3. PNG representing Betweenness Centrality
#Steps:
	1. python opens the exe file.
	2. exe file takes input from input.txt and puts the output in the stdout.
	3. python also reads text from input.txt and get number of node,number of edges and weights.
	4. create 2 lists for each algorithm to take the Centrality of each node
	 lists for each algorithms are:
	  	>>node_size_list_algorithm list with the (centrailty*10000) that will define size 
		  of the node in graph **(larger node size >>larger Centrality)**
	  	>>node_color_list_algorithm list with the (centrailty) that will define color 
	  	  of the node in graph **(Deeper node color >>larger Centrality)**
	7. create pipe between python and exe file
	8. using pipe take the output of exe file (centrality of each algorithm) and insert them in lists
	9. create Graph and edges with their weights using the input that we take from input.txt
	10. using networkx,we define the positions of nodes using circular layout 
	    for each algorithm:
	  	>>create figure png 
	 	>>using draw_nx to draw graph with color using node_color_list_algorithm and 
		  node size using node_color_list_algorithm
	  	>>save the drawing of graph in the png figure
