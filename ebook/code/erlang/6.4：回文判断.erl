%%%--------------------------------------
%%% @Module  : ispalindrome
%%% @Author  : hejavac@gmail.com
%%% @Created : 2014.5.30
%%% @Description:  字符串回文
%%%--------------------------------------
-module(ispalindrome).
-export([
        ispalindrome1/1,
        ispalindrome2/1
        ]).

%%--------------------------------------
%% @doc 回文,整个列表都检查,时间复杂度是2N=N+N,其中reverse函数时间复杂度是N,ispalindrome函数复杂度是N
-spec ispalindrome1(L) -> R when
        L  :: list(),
        R  :: boolean().  
%%--------------------------------------
ispalindrome1(L) when is_list(L) ->
    ispalindrome(L, lists:reverse(L)).

%%--------------------------------------
%% @doc 回文,只检查半个列表,这里时间复杂度是3.5N=N+N/2+N+N/2+N/2,其中length是N,reverse函数是N, 
%%      sublist函数是N/2,ispalindrome函数复杂度是N/2
-spec ispalindrome2(L) -> R when
        L  :: list(),
        R  :: boolean().  
%%--------------------------------------
ispalindrome2(L) when is_list(L) ->
    Half = length(L) div 2,
    L1 = lists:sublist(L, Half),
    L2 = lists:sublist(lists:reverse(L), Half),
    ispalindrome(L1, L2).

%%--------------------------------------
%% @doc 回文检查,输入如[1,2,3,4,]
-spec ispalindrome(L1, L2) -> R when
        L1 :: [T],
        L2 :: [T],
        R :: boolean(),     %% 是否回文
        T  :: term().   
%%--------------------------------------
ispalindrome([], []) ->
    true;
ispalindrome([E|L1], [E|L2]) ->
    ispalindrome(L1, L2);
ispalindrome(_, _) ->
    false.
   
%%--------------------------------------
%% @doc lists:reverse、lists:nth、sublist源码
%%--------------------------------------
reverse([] = L) ->
    L;
reverse([_] = L) ->
    L;
reverse([A, B]) ->
    [B, A];
reverse([A, B | L]) ->
    lists:reverse(L, [B, A]).

nth(1, [H|_]) -> H;
nth(N, [_|T]) when N > 1 ->
    nth(N - 1, T).

sublist(List, L) when is_integer(L), is_list(List) ->
    sublist_2(List, L).
 
sublist_2([H|T], L) when L > 0 ->
    [H|sublist_2(T, L-1)];
sublist_2(_, 0) ->
    [];
sublist_2(List, L) when is_list(List), L > 0 ->
    [].
