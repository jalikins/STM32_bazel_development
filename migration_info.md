## Migration of `bazel_lint`:

<details>
<summary>Click here to see where and how the repo was declared in the WORKSPACE file</summary>

#### Location
```python
Repository bazel_lint instantiated at:
  /home/jlikins/Documents/STM_HELL/second_bazel_stm32/WORKSPACE:6:13: in <toplevel>
Repository rule http_archive defined at:
  /home/jlikins/.cache/bazel/_bazel_jlikins/127343cd8a51fe4b90de4d39722f8c7d/external/bazel_tools/tools/build_defs/repo/http.bzl:387:31: in <toplevel>

```

#### Definition
```python
load("@@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
  name = "bazel_lint",
  url = "https://github.com/agoessling/bazel_lint/archive/v0.1.1.zip",
  sha256 = "85b8cab2998fc7ce32294d6473276ba70eea06b0eef4bce47de5e45499e7096f",
  strip_prefix = "bazel_lint-0.1.1",
)
```
**Tip**: URLs usually show which version was used.
</details>

___
	It is not found in BCR. 

	It has been introduced with `use_repo_rule`:

## Migration of `bazel_skylib`:

<details>
<summary>Click here to see where and how the repo was declared in the WORKSPACE file</summary>

#### Location
```python
Repository bazel_skylib instantiated at:
  /home/jlikins/Documents/STM_HELL/second_bazel_stm32/WORKSPACE:15:28: in <toplevel>
  /home/jlikins/.cache/bazel/_bazel_jlikins/127343cd8a51fe4b90de4d39722f8c7d/external/bazel_lint/bazel_lint/bazel_lint_first_level_deps.bzl:17:17: in bazel_lint_first_level_deps
Repository rule http_archive defined at:
  /home/jlikins/.cache/bazel/_bazel_jlikins/127343cd8a51fe4b90de4d39722f8c7d/external/bazel_tools/tools/build_defs/repo/http.bzl:387:31: in <toplevel>

```

#### Definition
```python
load("@@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
  name = "bazel_skylib",
  urls = [
    "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.3.0/bazel-skylib-1.3.0.tar.gz",
    "https://github.com/bazelbuild/bazel-skylib/releases/download/1.3.0/bazel-skylib-1.3.0.tar.gz"
  ],
  sha256 = "74d544d96f4a5bb630d465ca8bbcfe231e3594e5aae57e1edbf17a6eb3ca2506",
)
```
**Tip**: URLs usually show which version was used.
</details>

___
Found perfect name match in BCR: `bazel_skylib`

Found partially name matches in BCR: `bazel_skylib_gazelle_plugin`

It has been introduced as a Bazel module:

	bazel_dep(name = "bazel_skylib", version = "1.8.2")
## Migration of `rules_python`:

<details>
<summary>Click here to see where and how the repo was declared in the WORKSPACE file</summary>

#### Location
```python
Repository rules_python instantiated at:
  /home/jlikins/Documents/STM_HELL/second_bazel_stm32/WORKSPACE:15:28: in <toplevel>
  /home/jlikins/.cache/bazel/_bazel_jlikins/127343cd8a51fe4b90de4d39722f8c7d/external/bazel_lint/bazel_lint/bazel_lint_first_level_deps.bzl:9:17: in bazel_lint_first_level_deps
Repository rule http_archive defined at:
  /home/jlikins/.cache/bazel/_bazel_jlikins/127343cd8a51fe4b90de4d39722f8c7d/external/bazel_tools/tools/build_defs/repo/http.bzl:387:31: in <toplevel>

```

#### Definition
```python
load("@@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
  name = "rules_python",
  url = "https://github.com/bazelbuild/rules_python/archive/refs/tags/0.8.0.tar.gz",
  sha256 = "9fcf91dbcc31fde6d1edb15f117246d912c33c36f44cf681976bd886538deba6",
  strip_prefix = "rules_python-0.8.0",
)
```
**Tip**: URLs usually show which version was used.
</details>

___
Found perfect name match in BCR: `rules_python`

Found partially name matches in BCR: `rules_python_gazelle_plugin`

It has been introduced as a Bazel module:

	bazel_dep(name = "rules_python", version = "1.7.0")
## Migration of `platforms`:

<details>
<summary>Click here to see where and how the repo was declared in the WORKSPACE file</summary>

#### Location
```python
Repository platforms instantiated at:
  /DEFAULT.WORKSPACE.SUFFIX:147:6: in <toplevel>
  /home/jlikins/.cache/bazel/_bazel_jlikins/127343cd8a51fe4b90de4d39722f8c7d/external/bazel_tools/tools/build_defs/repo/utils.bzl:268:18: in maybe
Repository rule local_repository defined at:
  /home/jlikins/.cache/bazel/_bazel_jlikins/127343cd8a51fe4b90de4d39722f8c7d/external/bazel_tools/tools/build_defs/repo/local.bzl:64:35: in <toplevel>

```

#### Definition
```python
load("@@bazel_tools//tools/build_defs/repo:local.bzl", "local_repository")
local_repository(
  name = "platforms",
  path = "/home/jlikins/.cache/bazel/_bazel_jlikins/install/4c167c0b8ab075cf84abeb68c85d3968/platforms",
)
```
**Tip**: URLs usually show which version was used.
</details>

___
Found perfect name match in BCR: `platforms`

It has been introduced as a Bazel module:

	bazel_dep(name = "platforms", version = "1.0.0")
## Migration of `bazel_arm_toolchains`:

<details>
<summary>Click here to see where and how the repo was declared in the WORKSPACE file</summary>

#### Location
```python
Repository bazel_arm_toolchains instantiated at:
  /home/jlikins/Documents/STM_HELL/second_bazel_stm32/WORKSPACE:31:13: in <toplevel>
Repository rule http_archive defined at:
  /home/jlikins/.cache/bazel/_bazel_jlikins/127343cd8a51fe4b90de4d39722f8c7d/external/bazel_tools/tools/build_defs/repo/http.bzl:387:31: in <toplevel>

```

#### Definition
```python
load("@@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
  name = "bazel_arm_toolchains",
  url = "https://github.com/agoessling/bazel_arm_toolchains/archive/v0.1.1.zip",
  sha256 = "9b097099d1818a4a6a629918a7f6fd672a45ef8c32109cfe3375e97ee5087d86",
  strip_prefix = "bazel_arm_toolchains-0.1.1",
)
```
**Tip**: URLs usually show which version was used.
</details>

___
	It is not found in BCR. 

	It has been introduced with `use_repo_rule`:

Repository definition for `stm32cubef7` is not found in ./resolved_deps.py file, please add `--initial/-i` flag to force update it.
