defmodule TypeCheckingTest do
  use ExUnit.Case
  doctest TypeChecking

  test "greets the world" do
    assert TypeChecking.hello() == :world
  end
end
