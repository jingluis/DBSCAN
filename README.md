# DBSCAN

Density-based spatial clustering of applications with noise (DBSCAN) is a data clustering algorithm proposed by Martin Ester, Hans-Peter Kriegel, Jörg Sander and Xiaowei Xu in 1996. It is a density-based clustering non-parametric algorithm: given a set of points in some space, it groups together points that are closely packed together (points with many nearby neighbors), marking as outliers points that lie alone in low-density regions (whose nearest neighbors are too far away). DBSCAN is one of the most common clustering algorithms and also most cited in scientific literature.

## Usage

Example:

Run with parameters:

epsilon parameter (see more (wiki)[https://en.wikipedia.org/wiki/DBSCAN#Original_Query-based_Algorithm])

minimum number of points required to form a dense region parameter (default 10)

```
./dbscan 5 10 dataset.txt
```

## Output

* number of clusters and each cluster size
* plot with points, colored by cluster

Example:

![DBSCAN output](https://i.ibb.co/zmsJdVY/f.png)