#include "erl_nif.h"

static ERL_NIF_TERM
term_type(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {
    // See: https://github.com/erlang/otp/blob/2bcabe9e94d6328767729d8ff4def9bc229955ab/erts/emulator/beam/erl_nif.h#L320C10-L320C10
    switch (enif_term_type(env, argv[0])) {
    case ERL_NIF_TERM_TYPE_ATOM:
        return enif_make_atom(env, "atom");
    case ERL_NIF_TERM_TYPE_BITSTRING:
        return enif_make_atom(env, "bitstring");
    case ERL_NIF_TERM_TYPE_FLOAT:
        return enif_make_atom(env, "float");
    case ERL_NIF_TERM_TYPE_FUN:
        return enif_make_atom(env, "fun");
    case ERL_NIF_TERM_TYPE_INTEGER:
        return enif_make_atom(env, "integer");
    case ERL_NIF_TERM_TYPE_LIST:
        return enif_make_atom(env, "list");
    case ERL_NIF_TERM_TYPE_MAP:
        return enif_make_atom(env, "map");
    case ERL_NIF_TERM_TYPE_PID:
        return enif_make_atom(env, "pid");
    case ERL_NIF_TERM_TYPE_PORT:
        return enif_make_atom(env, "port");
    case ERL_NIF_TERM_TYPE_REFERENCE:
        return enif_make_atom(env, "reference");
    case ERL_NIF_TERM_TYPE_TUPLE:
        return enif_make_atom(env, "tuple");
    default:
        return enif_make_badarg(env);
    }
}

// Let's define the array of ErlNifFunc beforehand:
static ErlNifFunc nif_funcs[] = {
  // {erl_function_name, erl_function_arity, c_function}
  {"term_type", 1, term_type}
};

ERL_NIF_INIT(Elixir.TypeChecking, nif_funcs, NULL, NULL, NULL, NULL)
