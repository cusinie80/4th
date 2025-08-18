# Define the nodes and their corresponding heuristic values based on the given tree
sussList = {
    'a': [['b', 10], ['j', 8], ['f', 7]],    # Node a has successors b, j, and f with heuristic values 10, 8, and 7
    'b': [['d', 4], ['c', 2]],                # Node b has successors d and c with heuristic values 4 and 2
    'j': [['h', 0], ['k', 0]],                # Node j has successors h and k with heuristic values 0 and 0
    'f': [['e', 5], ['g', 3]],                # Node f has successors e and g with heuristic values 5 and 3
    'd': [],                                  # Node d has no successors
    'c': [],                                  # Node c has no successors
    'e': [],                                  # Node e has no successors
    'g': [],                                  # Node g has no successors
    'h': [],                                  # Node h has no successors
    'k': [],                                  # Node k has no successors
    'i': []                                   # Node i has no successors
}

# Define the initial node and its heuristic value
initial_node = 'a'  # Root node
initial_value = 10   # Heuristic value of root node 'a'

# Function to sort the selected list in ascending order based on heuristic value
def sortList(new_list):
    new_list.sort(key=lambda x: x[1])
    return new_list

# Hill climbing search algorithm to find the shortest path using heuristic value
def hillClimbing_search(node, value):
    if node in sussList.keys():
        new_list = sussList[node]
        new_list = sortList(new_list)
        if new_list:
            if value > new_list[0][1]:
                value = new_list[0][1]
                node = new_list[0][0]
                hillClimbing_search(node, value)
        else:
            print(f"ANSWER:\nFor given Data, the local maxima is at node '{node}' with heuristic value {value}")
    else:
        print(f"ANSWER:\nFor given Data, the local maxima is at node '{node}' with heuristic value {value}")

# Run the algorithm with the predefined initial node and value
hillClimbing_search(initial_node, initial_value)
