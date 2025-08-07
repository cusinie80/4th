import queue
adj_list={
    "a":["b","c","d"],
    "b":["e","f"],
    "c":["g"],
    "d":["h"],
    "e":[],
    "f":["i"],
    "g":["j"],
    "h":["k"],
    "i":[],
    "j":[],
    "k":[],
    }

output=[]
visited=[]
queue=[]

def bfsdemo(visited,graph,node):
    visited.append(node)
    queue.append(node)

    while queue:
        m=queue.pop(0)
        output.append(m)

        for neighbour in graph[m]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)
                
    print("traverse path=",output)
print("-----breadth first search-----")
startnode=input("enter the first node=")
bfsdemo(visited,adj_list,startnode)
