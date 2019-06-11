// n = number of vertices
E = { .. } // edges in original graph
T = {}; // spanning tree
while (T contains less than n-1 edges && E is not empty) {
  choose a least cost edge (v, w) from E;
  delete (v, w) from E;
  if ((v, w) does not create a cycle in T)
    add (v, w) to T;
  else
    discard (v, w);
}
if (T contains fewer than n-1 edges)
  printf("No spanning tree\n");