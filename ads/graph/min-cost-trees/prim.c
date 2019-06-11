T = {}; // edges in min spanning tree
TV = {0}; // vertex that has been visited, start w/ vertex 0 and no edges
while (T contains fewer than n-1 edges) {
  let (u, v) be a least cost edge ('u' from TV, 'v' not from TV)
  if (there is no such edge)
    break;
  add v to TV;
  add (u, v) to T;
}
if (T contains fewer than n-1 edges)
  printf("No spanning tree\n");