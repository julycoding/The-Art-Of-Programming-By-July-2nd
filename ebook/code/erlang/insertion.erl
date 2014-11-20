%% --------------------------------------------------------
%% @doc insertion sort
%% @author jpsiyu
%% @create 2014/11/20
%% @email jpsiyu@163.com
%% --------------------------------------------------------
-module(insertion).
-export([insert_list/1, insert_t_list/1]).

-define(STARTNUM, 2).

insert_out(TupleList, J) when J>length(TupleList) -> TupleList;
insert_out(TupleList, J) ->
	I = J-1, {_, Key} = lists:keyfind(J, 1, TupleList),
	NewTupleList = insert_in(TupleList, Key, I),
	insert_out(NewTupleList, J+1).

insert_in(TupleList, Key, I) when I =< 0 -> 
	lists:keyreplace(I+1, 1, TupleList, {I+1, Key});
insert_in(TupleList, Key, I) ->
	{_, V} = lists:keyfind(I, 1, TupleList),
	case  
		V > Key of true ->
			NewTupleList = lists:keyreplace(I+1, 1, TupleList, {I+1, V}),
			insert_in(NewTupleList, Key, I-1);
		_ -> 
			lists:keyreplace(I+1, 1, TupleList, {I+1, Key})
	end.

insert_t_list(TupleList) ->
	insert_out(TupleList, ?STARTNUM).

insert_list(List) ->
	TupleList = lists:zip(lists:seq(1, length(List)), List),
	ResList = insert_out(TupleList, ?STARTNUM),
	[V || {_, V} <- ResList].
