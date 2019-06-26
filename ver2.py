# -*- coding: utf-8 -*-
"""
Created on Sun May 19 16:53:44 2019

@author: Mark
"""

# -*- coding: utf-8 -*-
"""
Created on Sat May 18 14:22:58 2019

@author: Mark
"""
import networkx as nx
from subprocess import Popen, PIPE
import matplotlib.pyplot as plt
####
from matplotlib.colors import ListedColormap, LinearSegmentedColormap
viridis = plt.get_cmap(plt.cm.Blues, 256)
newcolors = viridis(np.linspace(0.3, 0.7, 256))
newcmp = ListedColormap(newcolors)
####
#open the exe file
p = Popen(['Project17.exe'], shell=True, stdout=PIPE, stdin=PIPE)
##Reading File
myfile = open("input.txt")
txt = myfile.read()
txt_lines=txt.split('\n')
myfile.close()
##
G=nx.Graph()
graph={}#for labels(weights)
node_size_list_Degree=[]#for node sizes.
node_size_list_Closeness=[]#for node sizes.
node_size_list_Betweenness=[]
node_color_list_Closeness=[]
node_color_list_Degree=[]
node_color_list_Betweenness=[]
##Spliting Text
x_list = txt_lines[0].split(' ') 
num_nodes = int(x_list[0])
num_edges=int(x_list[1])
##Creating Nodes
for n in range(0,num_nodes,1):
    G.add_node(n)  
    result = int(p.stdout.readline().strip())
    node_size_list_Degree.append(result*1000)
    node_color_list_Degree.append(result)
##Getting Values Of Closeness Algorithm
for n in range(0,num_nodes,1):
    result = float(p.stdout.readline().strip())
    node_size_list_Closeness.append(result*10000)
    node_color_list_Closeness.append(result)
##Getting Values Of Betweenness Algorithm
for n in range(0,num_nodes,1):
    result = float(p.stdout.readline().strip())
    node_size_list_Betweenness.append((result+1)*5000)
    node_color_list_Betweenness.append(result)
##inserting edges from txt file
for n in range(0,num_edges,1):
    x_list = txt_lines[n+1].split(' ') 
    fromIndex = int(x_list[0])
    toIndex=int(x_list[1])   
    egdeWeight=int(x_list[2])   
    G.add_edge(fromIndex,toIndex,weight=egdeWeight)
    graph[fromIndex,toIndex]=egdeWeight
 ##Positions of nodes     
graph_pos= nx.circular_layout(G)   
##Drawing Degree Algorithm Graph   
plt.show()
plt.figure(num=None, figsize=(20, 20), dpi=60)    
nx.draw(G,graph_pos,with_labels=True,node_color=node_color_list_Degree,cmap=newcmp,node_size =node_size_list_Degree,linewidths=10,font_color ='k',font_size =30 )
nx.draw_networkx_edge_labels(G,graph_pos, edge_labels =graph)
plt.savefig("Degree",bbox_inches="tight")
##Drawing Closeness Algorithm Graph   
plt.show()
plt.figure(num=None, figsize=(20, 20), dpi=60)
nx.draw(G,graph_pos,with_labels=True,node_color=node_color_list_Closeness,cmap=newcmp,node_size =node_size_list_Closeness,linewidths=10,font_color ='k',font_size =30)
nx.draw_networkx_edge_labels(G,graph_pos, edge_labels =graph)
plt.savefig("Closeness",bbox_inches="tight")
##Drawing Betweenness Algorithm Graph   
plt.show()
plt.figure(num=None, figsize=(20, 20), dpi=60)
nx.draw(G,graph_pos,with_labels=True,node_color=node_color_list_Betweenness,cmap=newcmp,node_size =node_size_list_Betweenness,linewidths=10,font_color ='k',font_size =30)
nx.draw_networkx_edge_labels(G,graph_pos, edge_labels =graph)
plt.savefig("Betweenness",bbox_inches="tight")