# Repository

This document describes the structure of this project's repository:
- [Branching model](#branching-model)
- [Folder structure](#folder-structure)

## <a id="branching-model"></a> Branching model

This repository relies on two main branches:
- [`master`](#bm-master)
- [`develop`](#bm-develop)

Additionally there are (many) minor branches:
- [`feature/...`](#bm-feature)
- [`bugfix/...`](#bm-bugfix)
- [`test/...`](#bm-test)
- [`junk/...`](#bm-junk)
- [`epic/...`](#bm-epic)
- [`release/...`](#bm-release)
- [`hotfix/...`](#bm-hotfix)
- [`ltsm/...`](#bm-ltsm)

---
### <a id="bm-master"></a> `master` - Branch

The `master` branch only contains production-ready code. Therefore, it is considered that the `HEAD` of `origin/master` always reflects the current production-ready state.

Each time when changes are merged back into `master`, this is a new production release by definition. It should be assigned and tagged with a version number (following the semantic versioning specification), the tag message should give a short description of the release like a changelog or a link to one;\
e.g. tag `4.7.11`: http://project.xyz/changelogs/v4.7.11/

New releases may be automatically build and rolled-out using continuous integration.

---
### <a id="bm-develop"></a> `develop` - Branch

The `develop` branch contains the current development changes. Therefore, it is considered that the `HEAD` of `origin/develop` reflects the current changes that will eventually form the next release.

This is where automatic nightly builds may be built from. "nightly"-builds should have a version number looking like `nightly+`*`<GIT-COMMIT-ID>`*;\
e.g. `nightly+b616550e`

---
### <a id="bm-feature"></a> `feature/...` - Branches

> __Branches off from:__ `develop` (or `epic/...`)
>
> __Merged back into:__ `develop` (or `epic/...`)
>
> __Naming convention:__ `feature/`*`<FEATURE-NAME>`*

In the `feature/...` branches the most part of development takes place. They are branched off of the `develop` branch, so that a new feature can be developed for a future release. Eventually (when the feature is finished) the branch will be merged back into the main `develop` branch.

If new commits in the `develop` branch are needed for the feature, the `feature/...` branch should be rebased.

If a feature gets discarded, the branch should be marked with a lightweight tag:
- `discarded/<FEATURE-NAME>` or
- `orphaned/<FEATURE-NAME>` or
- `junked/<FEATURE-NAME>`

`feature/...` branches may also branch off of an `epic/...` branch, which is used to encapsulate bigger changes. If so, it is not merged back ito the main `develop` branch, but into the `epic/...` branch it originated from.\
In the `git` commands below substitute `develop` for the specific `epic/...` branch.

#### <a id="bm-feature-instructions"></a> Creating a `feature/...` branch

```
$ git checkout develop
$ git branch feature/<FEATURE-NAME>
$ git checkout feature/<FEATURE-NAME>
```

#### Rebasing a `feature/...` branch to incorporate new `develop` commits
```
$ git rebase develop feature/<FEATURE-NAME>

[
    $ git rebase --continue
    $ git rebase --abort
]
```

#### Merging a `feature/...` branch into `develop`
```
$ git checkout develop
$ git merge [--no-ff] feature/<FEATURE-NAME>

[
    $ git merge --continue
    $ git merge --abort
]
```

#### Discarding a `feature/...` branch
```
$ git checkout feature/<FEATURE-NAME>
$ git tag <DISCARDED-TAG>
```
---
### <a id="bm-bugfix"></a> `bugfix/...` - Branches

> __Branches off from:__ `develop` (or `epic/...`)
>
> __Merged back into:__ `develop` (or `epic/...`)
>
> __Naming convention:__ `bugfix/`*`<BUG-NAME>`*

The `bugfix/...` branches are like `feature/...` branches, but they are used for fixing bugs instead of developing new features.

#### Creating, rebasing, merging & discarding ([goto](#bm-feature-instructions))
    Look at the instructions for feature/... branches

---
### <a id="bm-test"></a> `test/...` - Branches

> __Branches off from:__ `feature/...`, `bugfix/...` or `epic/...`
>
> __Merged back into:__ `NONE` (cherry-picked instead)
>
> __Naming convention:__ `test/`*`<WHAT-GETS-TESTED>`*

> Tests which do not require any additional infrastructure should be conducted in its related development branch (`feature/...`, etc.).

The `test/...` branches are used to test new features, bugfixes or even bigger changes if they require a specific test infrastructure. In these cases, the `test/...` branches may be used to setup the test environment and it may even be used to fix bugs that surface during the test. They are branched off the branch specifc to the changes that will be tested, but it is never merged back, because the test infrastructure may not be included in the main code base. Instead, successful bugfix commits done in a `test/...` branch are cherry-picked into the respective development branch (`feature/...`, etc.).

If development in the base branch continued and should now be tested again using the same (or a similar) test environment, the `test/...` branch should be rebased.

#### Creating a `test/...` branch
```
$ git checkout <BASE-BRANCH>
$ git branch test/<WHAT-GETS-TESTED>
$ git checkout test/<WHAT-GETS-TESTED>
```

#### Rebasing a `test/...` branch to incorporate / test new development commits
```
$ git rebase <BASE-BRANCH> test/<WHAT-GETS-TESTED>

[
    $ git rebase --continue
    $ git rebase --abort
]
```

#### Cherry-picking fixes from a `test/...` branch into its base branch
```
$ git checkout <BASE-BRANCH>
$ git cherry-pick <FIX-COMMIT>

[
    $ git cherry-pick --continue
    $ git cherry-pick --abort
]
```

---
### <a id="bm-junk"></a> `junk/...` - Branches

> __Branches off from:__ `EVERYWHERE`
>
> __Merged back into:__ `NONE`
>
> __Naming convention:__ `junk/`*`<NAME>`*

`junk/...` branches are used for (random) experiments, proofs of concept, etc. They may branch off of every other branch, but may never be merged back into any branch (except maybe other `junk/...` branches).

If it is expected that the changes that are made in this branch will be merged back into another branch eventually, consider using another branch type like:
- `feature/...`
- `epic/...`

#### Creating a `junk/...` branch
```
$ git checkout <SOME-BRANCH>
$ git branch junk/<NAME>
$ git checkout junk/<NAME>
```

---
### <a id="bm-epic"></a> `epic/...` - Branches

> __Branches off from:__ `develop`
>
> __Merged back into:__ `develop`
>
> __Naming convention:__ `epic/`*`<EPIC-NAME>`*

The `epic/...` branches are very similar to `feature/...` branches, but are used to encapsulate not only single features but bigger changes. Code changes may be made directly in the `epic/...` branch or grouped into sub-features, bugfixes, etc.. In this case, `feature/...` and `bugfix/...` branches branching off of this `epic/...` branch are used to build that structure (the `epic/...` branch is then acting like the main `develop` branch for those sub-branches).

To start development on such bigger changes an `epic/...` branch is created from `develop`. After those big changes are done, `epic/...` is merged back into the main `develop` branch.

Like `feature/...` branches, `epic/...`'s may also be rebased and discarded.

#### Creating, rebasing, merging & discarding ([goto](#bm-feature-instructions))
    Look at the instructions for feature/... branches

---
### <a id="bm-release"></a> `release/...` - Branches

> __Branches off from:__ `develop`
>
> __Merged back into:__ `master`, `develop` (and `release/...`)
>
> __Naming convention:__ `release/v`*`<VERSION-NUMBER>`*

__*TODO: Write documentation for release branches*__

---
### <a id="bm-hotfix"></a> `hotfix/...` - Branches

> __Branches off from:__ `master`, (or `ltsm/...`)
>
> __Merged back into:__ `master`, `develop` (and `release/...`) (+ `ltsm/...`)
>
> __Naming convention:__ `hotifx/`*`<FIX-NAME>`*

__*TODO: Write documentation for hotfix branches*__

---
### <a id="bm-ltsm"></a> `ltsm/...` - Branches

> __Branches off from:__ `master`
>
> __Merged back into:__ `NONE`
>
> __Naming convention:__ `ltsm/v`*`<VERSION-NUMBER>`*

Long-term support & maintenance branches...\
__*TODO: Write documentation for ltsm branches*__

---
### Additional info
If erroneous commits have been made, they can be undone by using: `$ git reset [...]` or `$ git revert <COMMIT-TO-MAKE-UNDONE>`

If enough time has passed and branches are no longer needed, (short-lived) branches may be removed from the history using: `$ git branch -d <BRANCH-TO-REMOVE>`

__*This branching model is based on the [successful Git branching model](http://nvie.com/posts/a-successful-git-branching-model/) of Vincent Driessen.*__

---
---
## <a id="folder-structure"></a> Folder structure

__*TODO: Write documentation for this projects folder structure*__
