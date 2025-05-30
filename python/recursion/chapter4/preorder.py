root = {'data': 'A', 'chiildren':[]}
node2 = {'data': 'B', 'children':[]}
node3 = {'data': 'C', 'children':[]}
node4 = {'data': 'D', 'children':[]}
node5 = {'data': 'E', 'children':[]}
node6 = {'data': 'F', 'children':[]}
node7 = {'data': 'G', 'children':[]}
node8 = {'data': 'H', 'children':[]}
root['children'] = [node2, node3];
node2['children'] = [node4];
node3['children'] = [node5, node6];
node5['children'] = [node7, node8];

# traverse preorder
# go to the first node first, then the leftmost

# base case? no more children
# input to recursive calls next child nodes
# it gets closer to the end each time

def preorder(root):
    if len(root['children']) == 0:
        print(root['data'])
        return
    print(root['data'])
    for child in root['children']:
        preorder(child)
    return

# preorder(root)

def postorder(root):
    if len(root['children']) == 0:
        print(root['data'])
        return
    for child in root['children']:
        postorder(child)
    print(root['data'])
    return

# inorder(root)

def inorder(root):
    if len(root['children']) == 0:
        print(root['data'])
        return
    if len(root['children']) >= 1:
        inorder(root['children'][0])
    print(root['data'])
    if len(root['children']) >= 2:
        inorder(root['children'][1])
    return

# inorder(root)

nametree = {'name': 'Alice', 'children': [{'name': 'Bob', 'children':
[{'name': 'Darya', 'children': []}]}, {'name': 'Caroline',
'children': [{'name': 'Eve', 'children': [{'name': 'Gonzalo',
'children': []}, {'name': 'Hadassah', 'children': []}]}, {'name': 'Fred', 'children': []}]}]}

def findeight(node):
    if len(node['children']) == 0:
        return None
    # recurse 
    res1 = None
    res2 = None
    if len(node['children']) >= 1:
        res1 = findeight(node['children'][0])
    if len(node['children']) >= 2:
        res2 = findeight(node['children'][1])

    # do work
    if res1:
        return res1
    if res2:
        return res2
    if len(node['name']) == 8:
        return node

print(findeight(nametree)['name'])
