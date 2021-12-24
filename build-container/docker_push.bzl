load(":expand_template.bzl", "expand_template")

def docker_push(name, registry, repository, tag, **kwargs):
    """Push the given docker image.
    """
    docker_image = "{registry}/{repository}:{tag}".format(registry = registry, repository = repository, tag = tag)
    out_name = docker_image.replace(":", "_").replace('/', '-')

    return expand_template(
        name = name,
        template = "docker_push.sh.j2",
        substitutions = {
            "{{ docker_image }}": docker_image,
        },
        out = "docker_push_{out_name}.sh".format(out_name = out_name),
        is_executable = True,
    )
