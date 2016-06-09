#include "count_operations.h"
#include "functorized.h"
#include <cstdio>

int main() {  
  if(std::freopen("sort-ops.txt","w",stdout)){
    count_operations(16, 16 * 1024 * 1024, sort_functor());
    std::fclose(stdout);
  }
  if(std::freopen("sort-ops-norm.txt","w",stdout)){
    count_operations(16, 16 * 1024 * 1024, sort_functor(), normalized_by_nlogn1);
    std::fclose(stdout);
  }
  if(std::freopen("sort-unique-ops.txt","w",stdout)){
    count_operations(16, 16 * 1024 * 1024, sort_unique_functor());
    std::fclose(stdout);
  }
  if(std::freopen("sort-unique-ops-norm.txt","w",stdout)){
    count_operations(16, 16 * 1024 * 1024, sort_unique_functor(), normalized_by_nlogn1);
    std::fclose(stdout);
  }
  if(std::freopen("setsort-ops.txt","w",stdout)){
    count_operations(16, 16 * 1024 * 1024, setsort_functor());
    std::fclose(stdout);
  }
  if(std::freopen("setsort-ops-norm.txt","w",stdout)){
    count_operations(16, 16 * 1024 * 1024, setsort_functor(), normalized_by_nlogn1);
    std::fclose(stdout);
  }
  if(std::freopen("setsort-unique-ops.txt","w",stdout)){
    count_operations(16, 16 * 1024 * 1024, setsort_unique_functor());
    std::fclose(stdout);
  }
  if(std::freopen("setsort-unique-ops-norm.txt","w",stdout)){
    count_operations(16, 16 * 1024 * 1024, setsort_unique_functor(), normalized_by_nlogn1);
    std::fclose(stdout);
  }
  if(std::freopen("stable-sort-ops.txt","w",stdout)){
    count_operations(16, 16 * 1024 * 1024, stable_sort_functor());
    std::fclose(stdout);
  }
  if(std::freopen("stable-sort-ops-norm.txt","w",stdout)){
    count_operations(16, 16 * 1024 * 1024, stable_sort_functor(), normalized_by_nlogn1);
    std::fclose(stdout);
  }
  if(std::freopen("heap-sort-ops.txt","w",stdout)){
    count_operations(16, 16 * 1024 * 1024, heap_sort_functor());
    std::fclose(stdout);
  }
  if(std::freopen("heap-sort-ops-norm.txt","w",stdout)){
    count_operations(16, 16 * 1024 * 1024, heap_sort_functor(), normalized_by_nlogn1);
    std::fclose(stdout);
  }
}
