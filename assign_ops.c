#include "push_swap.h"

void	assign_pos(t_stack *b)
{
	int	len;

	len = lstlen(b);
	if (len % 2 == 0)
		assign_pos_even(b);
	else
		assign_pos_odd(b);
}

void	assign_pos_odd(t_stack *b)
{
	t_stack *last;
        int     i;
        int     median;
        int     flag;

        i = 0;
        median = lstlen(b) / 2;
        flag = 2;
        last = b;
        while (b)
        {
		if (i > median)
                        flag = 0;  
                if (flag > 1)
                {
                        b->median_flag = 0;
                        b->pos = i;
                        i++;
                }
		else if (flag == 1)
			flag = 0;
                else
                {
                        i--;
                        b->median_flag = 1;
                        b->pos = i;
                }
                b = b->next;
        }
        if (lstlen(last) == 1)
                return ;
        while (last->next)
                last = last->next;
        last->pos = 1;
}

void assign_pos_even(t_stack *b)
{
        t_stack *last;
        int     i;
        int     median;
        int     flag;

	i = 0;
        median = lstlen(b) / 2;
        flag = 1;
        last = b;
        while (b)
        { 
 		if (i >= median)
                        flag = 0; 
                if (flag)
                {
                        b->median_flag = 0;
                        b->pos = i;
			i++;
                }
                else
                {
                        b->median_flag = 1;
                        b->pos = i;
                        i--;
                }
               b = b->next;
        }
        if (lstlen(last) == 1)
                return ;
        while (last->next)
                last = last->next;
        last->pos = 1;
}

void assign_target(t_stack *a, t_stack *b)
{
        t_stack *target;
        t_stack *tmp;

        tmp = a;
        while (b)
        {
                a = tmp;
                target = 0;
                while (a)
                {
                        if (target && (a->x < target->x && a->x > b->x))
                                target = a;
                        else if (!target && a->x > b->x)
                                target = a;
                        a = a->next;
                }
                b->target = target;
                b = b->next;
        }
}
