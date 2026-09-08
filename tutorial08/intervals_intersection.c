#include <stdio.h>
#include <stdbool.h>

struct interval {
  double start;
  double end;
};

bool find_intervals_intersection(struct interval interval1, struct interval interval2, struct interval *result){
  double max_start = interval1.start > interval2.start ? interval1.start : interval2.start;
  double min_end = interval1.end < interval2.end ? interval1.end : interval2.end;

  if(max_start <= min_end){
    result->start=max_start;
    result->end=min_end;
    return true;
  }
  return false;
}

int main(){
  struct interval interval1;
  struct interval interval2;
  struct interval intersection;
  interval1.start=1;
  interval1.end=5;
  interval2.start=3;
  interval2.end=8;
  bool res = find_intervals_intersection(interval1, interval2, &intersection);
  printf("Interval1: [%lf,%lf] a Interval2: [%lf,%lf]: se %s\n", interval1.start,interval1.end,interval2.start,interval2.end, res?"Protinaji":"Neprotinaji");
  return 0;
}