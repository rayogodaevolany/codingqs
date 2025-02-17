def rec(node):
    if not node.right and not node.left:
        return [[node.val]]
    res = []
    nodeArr = [node.val]
    leftAll = rec(node.left)
    for x in leftAll:
        res.append(nodeArr + x)
    rightAll = rec(node.right)
    for x in rightAll:
        res.append(nodeArr + x)
    return res
