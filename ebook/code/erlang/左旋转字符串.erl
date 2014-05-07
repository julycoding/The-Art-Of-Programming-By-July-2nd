%%%-----------------------------------
%%% @Module      : july_1_1
%%% @Author      : hejavac
%%% @Email       : hejavac@gmail.com
%%% @Created     : 创建日期
%%% @Description : 1.1、左旋转字符串 : 字符串旋转问题,例如abcdef 左旋2位 变成 cdefab
%%%-----------------------------------

-module(july_1_1).

-compile(export_all).

%% 启动
%% Str:字符串
%% Step:位移量
%% 返回:位移后的字符串
start(Str, Step) -> 
    shift(Str, Step).	

%% 字符串位移递归函数
%% Str:字符串
%% Step:位移量
%% 返回:位移后的字符串
shift(S, 0) ->
    S;
shift([T|S], Step) ->
    %或者是:shift(lists:concat([S, [T]]), Step-1).
    shift(S ++ [T], Step-1).

%% 测试（bcdef 左旋2位 变成 cdefab）
test() ->
    dbg:tracer(),
    dbg:p(all,[c]),
    dbg:tpl(?MODULE, [{'_', [], [{return_trace}]}]),
    start("abcdef", 2).
