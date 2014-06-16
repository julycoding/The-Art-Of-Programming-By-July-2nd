%%%--------------------------------------
%%% @Module  : binary_search
%%% @Author  : hejavac@gmail
%%% @Created : 2014.5.23
%%% @Description:  二分查找V0.1实现版
%%%--------------------------------------
-module(binary_search).
-compile(export_all).

%%--------------------------------------
%% @doc 二分查找算法初始化,Left初始值是1,Right是列表的长度。
-spec binary_search(L, Value) -> Pos when
      L :: list,
      Value :: integer(),
      Pos :: integer(). %%(返回0则是查找失败)
%%--------------------------------------
binary_search(L, Value) when is_list(L) ->
    Left = 1,
    Right = length(L), 
    {Mid, MidValue} = get_Mid_and_MidValue(L, Left, Right),
    binary_search(L, Mid, MidValue, Left, Right, Value);
binary_search(_L, _Value) ->
    is_not_list. 

%%  二分查找V0.1实现版
%%  首先要把握下面几个要点：
%%  right = n-1 => while(left <= right) => right = middle-1;
%%  right = n   => while(left <  right) => right = middle;
%%  middle的计算不能写在while循环外，否则无法得到更新。

%%--------------------------------------
%% @doc 二分查找算法,使用匹配递归模拟while循环。
-spec binary_search(L, Mid, MidValue, Left, Right, Value) -> Pos when
      L :: integer(),
      Mid :: integer(),
      MidValue :: integer(),
      Left :: integer(),
      Right :: integer(),
      Value :: integer(),
      Pos :: integer().%%(返回0则是查找失败)
%% @end
%%--------------------------------------
binary_search(_L, _Mid, _MidValue, Left, Right, _Value) when Left > Right ->
    0;
binary_search(L, Mid, MidValue, Left, _Right, Value) when MidValue > Value ->
    NewRight = Mid - 1,
    {NewMid, NewMidValue} = get_Mid_and_MidValue(L, Left, NewRight),
    binary_search(L, NewMid, NewMidValue, Left, NewRight, Value);
binary_search(L, Mid, MidValue, _Left, Right, Value) when MidValue < Value ->
    NewLeft = Mid + 1,
    {NewMid, NewMidValue} = get_Mid_and_MidValue(L, NewLeft, Right),
    binary_search(L, NewMid, NewMidValue, NewLeft, Right, Value);
binary_search(_L, Mid, MidValue, _Left, _Right, Value) when MidValue =:= Value ->
    Mid.

%% @doc 获取Left和Right的中间位置和中间值
get_Mid_and_MidValue(L, Left, Right) ->
    Mid = (Left + Right) div 2,
    if
        Mid =:= 0 ->
            {0, 0};
        true ->
            MidValue = lists:nth(Mid, L),
            {Mid, MidValue}
    end.
