import numpy as np
import networkx as nx

def create_subgraph(adjacency_matrix, node_indices, node_labels):
    subgraph_matrix = adjacency_matrix[node_indices][:, node_indices]
    subgraph = nx.Graph(subgraph_matrix)
    subgraph = nx.relabel_nodes(subgraph, {i: node_labels[i] for i in node_indices})
    return subgraph

def random_partition_with_node_ids(adjacency_matrix, node_labels):
    assert len(adjacency_matrix) == len(adjacency_matrix[0]), "The adjacency matrix must be a square matrix."
    assert len(adjacency_matrix) == len(node_labels), "The number of node labels must match the size of the adjacency matrix."

    num_nodes = len(adjacency_matrix)
    node_indices = np.random.permutation(num_nodes)
    partition_size = num_nodes // 4

    subgraph1_nodes = node_indices[:partition_size]
    subgraph2_nodes = node_indices[partition_size:2 * partition_size]
    subgraph3_nodes = node_indices[2 * partition_size:3 * partition_size]
    subgraph4_nodes = node_indices[3 * partition_size:]

    subgraph1 = create_subgraph(adjacency_matrix, subgraph1_nodes, node_labels)
    subgraph2 = create_subgraph(adjacency_matrix, subgraph2_nodes, node_labels)
    subgraph3 = create_subgraph(adjacency_matrix, subgraph3_nodes, node_labels)
    subgraph4 = create_subgraph(adjacency_matrix, subgraph4_nodes, node_labels)

    return subgraph1, subgraph2, subgraph3, subgraph4

# 示例用法
# 假设你有一个包含16个节点的图的邻接矩阵和节点编号
adjacency_matrix_16_nodes = np.array([[0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                                      [1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                                      [0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                                      [1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
                                      [1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
                                      [0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0],
                                      [0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0],
                                      [0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0],
                                      [0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0],
                                      [0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0],
                                      [0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0],
                                      [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1],
                                      [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0],
                                      [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0],
                                      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1],
                                      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0]])

node_labels = [f"Node_{i}" for i in range(len(adjacency_matrix_16_nodes))]

# 获取子图
subgraph1, subgraph2, subgraph3, subgraph4 = random_partition_with_node_ids(adjacency_matrix_16_nodes, node_labels)

# 输出子图信息
print("Subgraph 1 Nodes:", subgraph1.nodes)
print("Subgraph 1 Adjacency Matrix:\n")
print(adjacency_matrix_16_nodes[subgraph1.nodes])

# print("\nSubgraph 2 Nodes:", subgraph2.nodes)
# print("Subgraph 2 Adjacency Matrix:\n", adjacency_matrix_16_nodes[subgraph2.nodes][:, subgraph2.nodes])

# print("\nSubgraph 3 Nodes:", subgraph3.nodes)
# print("Subgraph 3 Adjacency Matrix:\n", adjacency_matrix_16_nodes[subgraph3.nodes][:, subgraph3.nodes])

# print("\nSubgraph 4 Nodes:", subgraph4.nodes)
# print("Subgraph 4 Adjacency Matrix:\n", adjacency_matrix_16_nodes[subgraph4.nodes][:, subgraph4.nodes])
