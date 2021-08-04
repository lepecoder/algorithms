#include <bits/stdc++.h>
using namespace std;

class LRUCache {
  public:
    /**
     * 使用unordered_map存储键值对，实现O(1)的查找
     * 为了维护数据的使用顺序，需要一个可以快速删除任意
     * 位置和在头部插入的数据结构，使用链表是合适的。
     * 表头是最新访问的元素，表尾是最后访问的元素，
     * 线性表的查找时间是O(n)的，为了实现O(1)的时间
     * 复杂度，我们用map存储list中的节点指针
     */
    struct Dlist { // 双链表
        int val, key;
        Dlist *pre;
        Dlist *next;
        Dlist() : val(-1), key(-1), next(nullptr), pre(nullptr) {}
        Dlist(int k, int v) : key(k), val(v), next(nullptr), pre(nullptr) {}
    };
    int maxCap;
    Dlist *head, *tail;
    unordered_map<int, Dlist *> mp;

    LRUCache(int capacity) {
        maxCap = capacity;
        head = new Dlist();
        tail = new Dlist();
        head->next = tail;
        tail->pre = head;
    }
    void removeNode(Dlist *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        // delete node;
    }
    void addToHead(Dlist *node) {
        node->next = head->next;
        node->pre = head;
        head->next = node;
        node->next->pre = node;
    }
    Dlist *removeTail() {
        Dlist *node = tail->pre;
        removeNode(node);
        return node;
    }

    int get(int key) {
        if (mp.count(key) == 0) { return -1; }
        // 更新链表，将key移到链表头
        Dlist *node = mp[key];
        removeNode(node);
        addToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        // 如果缓存满了就删除最后一个节点
        // 如果是更新value就删除key那个节点
        // 如果都不是就不删除节点
        // 但是都要插入新节点
        if (mp.count(key)) { // key存在，只需要修改值
            Dlist *node = mp[key];
            removeNode(node);
            node->val = value;
            addToHead(node);
        } else { // key不存在，需要增加新节点
            Dlist *node = new Dlist(key, value);
            addToHead(node);
            mp[key] = node;
            if (mp.size() > maxCap) { // 移除尾节点
                Dlist *removed = removeTail();
                mp.erase(removed->key);
                delete removed;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */