//
// Created by Artur Gabasov on 6/24/23.
//
struct point	p;
struct point	q;
int				n;
int				g;
struct point	*p_ptr;

n = 2;
g = 5;
p.x = 1;
p.y = -5;
p.ptr = &n;
printf("x du p est %d, y du p est %d, *ptr du p est %d\n", p.x, p.y,
*(p.ptr));

p_ptr = &p;
(*p_ptr).x = 2;
p_ptr->y = 10;
*(p.ptr) = 3;
printf("x du p est %d, y du p est %d, n est %d\n", p.x, p.y, n);

(*p_ptr).x = 2;
p_ptr->y = 10;
(p_ptr->ptr) = &g;
printf("x du p est %d, y du p est %d, *ptr du p est %d\n",
p.x, p.y, *(p.ptr));

q.x = 99;
q.y = 100;
p_ptr->point_ptr = &q;
printf("x du point_ptr du p_ptr est %d\n",
p_ptr->point_ptr->x);
