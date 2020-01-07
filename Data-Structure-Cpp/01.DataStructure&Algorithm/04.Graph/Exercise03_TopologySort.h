#pragma once
#include "Exercise00_GraphTools.h"

/*��������*/
vector<GraphNode*> TopologySort(Graph* graph) {
	if (&graph == nullptr || &(graph->nodes_) == nullptr) {
		return {};
	}
	unordered_map<GraphNode*, int> in_map;
	queue<GraphNode*> zero_in;
	// ��¼��ʼ��ȣ����Ϊ0ֱ�ӽ�����
	for (auto it = graph->nodes_.begin(); it != graph->nodes_.end(); it++) {
		in_map.insert(pair<GraphNode*, int>(it->second, it->second->in_));
		if (it->second->in_ == 0) {
			zero_in.push(it->second);
		}
	}
	vector<GraphNode*> result;
	while (!zero_in.empty()) {
		GraphNode* cur = zero_in.front();
		zero_in.pop();
		result.push_back(cur);
		for (auto it = cur->nexts_.begin(); it != cur->nexts_.end(); it++) {
			GraphNode* next = *it;
			in_map.insert(pair<GraphNode*, int>(next, in_map.at(next)--));
			if (in_map[next] == 0) {
				zero_in.push(next);
			}
		}
	}
	return result;
}