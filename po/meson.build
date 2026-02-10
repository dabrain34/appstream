
as_gettext_domain = 'appstream'
i18n_result = i18n.gettext(as_gettext_domain,
    preset : 'glib',
    data_dirs: [join_paths(source_root, 'data')],
    args: [
        '--default-domain=' + as_gettext_domain,
        '--from-code=UTF-8',
        '-i', '-F', '-c', '--no-wrap',
        '--package-name=' + as_gettext_domain,
        '--copyright-holder=Matthias Klumpp',
        '--msgid-bugs-address=appstream@lists.freedesktop.org'
    ]
)

run_target ('make-linguas',
    command: [find_program('python3', 'python'),
              join_paths(source_root, 'contrib/meson/update-linguas.py')]
)

# maintainer shortcut for updating l10n data
run_target ('l10n-update',
    command: [
        'ninja', '-C', meson.project_build_root(),
        'make-linguas',
        as_gettext_domain + '-pot',
    ]
)
