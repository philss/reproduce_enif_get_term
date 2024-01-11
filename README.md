# TypeChecking

First export the path to ERTS:

```sh
set -x ERL_INCLUDE_PATH /home/philip/.asdf/installs/erlang/25.3/erts-13.2/include
```

And compile with:

```sh
zig cc -fPIC -I$ERL_INCLUDE_PATH \
        -dynamiclib -undefined dynamic_lookup \
        -o type_checking.so type_checking.c
```

You can now use the project from iex.

## Installation

If [available in Hex](https://hex.pm/docs/publish), the package can be installed
by adding `type_checking` to your list of dependencies in `mix.exs`:

```elixir
def deps do
  [
    {:type_checking, "~> 0.1.0"}
  ]
end
```

Documentation can be generated with [ExDoc](https://github.com/elixir-lang/ex_doc)
and published on [HexDocs](https://hexdocs.pm). Once published, the docs can
be found at <https://hexdocs.pm/type_checking>.

