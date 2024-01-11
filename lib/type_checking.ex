defmodule TypeChecking do
  @on_load :load_nifs

  def load_nifs do
    :erlang.load_nif(~c"./type_checking", 0)
  end

  def term_type(_a), do: raise("NIF get_type is not loaded yet")
end
